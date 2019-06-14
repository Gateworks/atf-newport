#include <gsern/gsern_internal.h>

#include <string.h>
#include <platform_def.h>
#include <platform_dt.h>
#include <plat_board_cfg.h>
#include <stdarg.h>
#include <libfdt.h>
#include <stdlib.h>

int gsern_is_platform(int plat)
{
	return strncmp(plat_octeontx_bcfg->bcfg.board_model,
		plat == GSERN_PLATFORM_ASIM ? "asim-" : "emul-", 5);
}

int gsern_poll_for_csr(uint64_t addr, uint64_t mask, int poll_val, int timeout)
{
	uint64_t val;

	do {
		/*
		 * NOTE : directly read from addr instead of using
		 * CSR_READ in this case to avoid dependencies
		 */
		val = cavm_le64_to_cpu(*(volatile uint64_t *)addr);
		/*
		 * argument poll_val indicates if the bit should
		 * be polled for value of 1 or 0
		 */
		if ((poll_val && (val & mask)) || (!poll_val && !(val & mask)))
			break;
		udelay(1);
	} while (--timeout > 0);

	if (!timeout)
		return -1;

	return 0;
}

const char *qlm_mode_to_cfg_str(qlm_modes_t mode)
{
#define MODE_CASE(m) case m: return ((const char *)#m)+9
	switch (mode) {
	MODE_CASE(QLM_MODE_DISABLED);
	MODE_CASE(QLM_MODE_PCIE_X1);
	MODE_CASE(QLM_MODE_PCIE_X2);
	MODE_CASE(QLM_MODE_PCIE_X4);
	MODE_CASE(QLM_MODE_PCIE_X8);
	MODE_CASE(QLM_MODE_PCIE_X16);

	MODE_CASE(QLM_MODE_SATA);

	MODE_CASE(QLM_MODE_SGMII);
	MODE_CASE(QLM_MODE_1G_X);
	MODE_CASE(QLM_MODE_QSGMII);
	MODE_CASE(QLM_MODE_XAUI);
	MODE_CASE(QLM_MODE_RXAUI);
	MODE_CASE(QLM_MODE_XFI);
	MODE_CASE(QLM_MODE_SFI);
	MODE_CASE(QLM_MODE_XLAUI);
	MODE_CASE(QLM_MODE_XLAUI_C2M);
	MODE_CASE(QLM_MODE_10G_KR);
	MODE_CASE(QLM_MODE_40G_CR4);
	MODE_CASE(QLM_MODE_40G_KR4);
	MODE_CASE(QLM_MODE_20GAUI_C2C);
	MODE_CASE(QLM_MODE_25GAUI_C2C);
	MODE_CASE(QLM_MODE_25GAUI_C2M);
	MODE_CASE(QLM_MODE_25G_CR);
	MODE_CASE(QLM_MODE_25G_KR);
	MODE_CASE(QLM_MODE_40GAUI_2_C2C);
	MODE_CASE(QLM_MODE_50GAUI_2_C2C);
	MODE_CASE(QLM_MODE_50GAUI_2_C2M);
	MODE_CASE(QLM_MODE_50G_CR2);
	MODE_CASE(QLM_MODE_50G_KR2);
	MODE_CASE(QLM_MODE_80GAUI_4_C2C);
	MODE_CASE(QLM_MODE_CAUI_4_C2C);
	MODE_CASE(QLM_MODE_CAUI_4_C2M);
	MODE_CASE(QLM_MODE_100G_CR4);
	MODE_CASE(QLM_MODE_100G_KR4);
	MODE_CASE(QLM_MODE_USXGMII_4X1);
	MODE_CASE(QLM_MODE_USXGMII_2X1);
	MODE_CASE(QLM_MODE_USXGMII_1X1);

	case QLM_MODE_LAST:
		break; /* fall through error */
	}
#undef MODE_CASE

	return "INVALID_QLM_MODE_VALUE";
}

static int gsern_config_get_qlm_tuning(int prop, const char *mode, int baud_mhz,
	int qlm, int lane)
{
	char name[64];
	const char *type, *buf;
	const void *fdt = fdt_ptr;
	int offset, rc, len;

	rc = fdt_check_header(fdt);
	if (rc) {
		WARN("Invalid device tree\n");
		return -1;
	}

	offset = fdt_path_offset(fdt, "/cavium,bdk");
	if (offset < 0) {
		WARN("FDT node not found\n");
		return -1;
	}


	switch (prop) {
	case GSERN_CONFIG_QLM_TUNING_TX_MAIN:
		type = GSERN_CONFIG_QLM_TUNING_TX_MAIN_NAME;
		break;
	case GSERN_CONFIG_QLM_TUNING_TX_PRE:
		type = GSERN_CONFIG_QLM_TUNING_TX_PRE_NAME;
		break;
	case GSERN_CONFIG_QLM_TUNING_TX_POST:
		type = GSERN_CONFIG_QLM_TUNING_TX_POST_NAME;
		break;
	case GSERN_CONFIG_QLM_TUNING_TX_BS:
		type = GSERN_CONFIG_QLM_TUNING_TX_BS_NAME;
		break;
	default:
		WARN("Unknown property to read from BDK DT\n");
		return -1;
	}

	snprintf(name, sizeof(name), "QLM-TUNING-TX-%s.%s.%d.N0.QLM%d.LANE%d",
		type, mode, baud_mhz, qlm, lane);

	buf = fdt_getprop(fdt, offset, name, &len);
	if (!buf) {
		debug_gsern("No %s option is set in BDK DT.\n", prop);
		return -1;
	}
	return strtol(buf, NULL, 10);
}

static int gsern_get_lane_config(int prop, int qlm, int lane)
{
	switch (prop) {
	case GSERN_CONFIG_QLM_LANE_RX_POLARITY:
		return plat_octeontx_bcfg->qlm_cfg[qlm].lane_rx_polarity[lane];
	case GSERN_CONFIG_QLM_LANE_TX_POLARITY:
		return plat_octeontx_bcfg->qlm_cfg[qlm].lane_tx_polarity[lane];
	case GSERN_CONFIG_QLM_TUNING_RX_PREVGA_GN_OVRD:
		return plat_octeontx_bcfg->qlm_cfg[qlm]
						.lane_rx_prevga_gn_ovrd[lane];
	case GSERN_CONFIG_QLM_TUNING_RX_PREVGA_GN_ADAPT:
		return plat_octeontx_bcfg->qlm_cfg[qlm]
						.lane_rx_prevga_gn_adapt[lane];
	default:
		WARN("Unknown property to read from BDK DT\n");
		return -1;
	}
}

int gsern_config_get_int(int prop, ...)
{
	int ret;
	int qlm, lane, baud_mhz;
	const char *mode;
	va_list vl;

	va_start(vl, prop);

	switch (prop) {
	case GSERN_CONFIG_QLM_LANE_RX_POLARITY:
	case GSERN_CONFIG_QLM_LANE_TX_POLARITY:
	case GSERN_CONFIG_QLM_TUNING_RX_PREVGA_GN_OVRD:
	case GSERN_CONFIG_QLM_TUNING_RX_PREVGA_GN_ADAPT:
		qlm = va_arg(vl, int);
		lane = va_arg(vl, int);
		ret = gsern_get_lane_config(prop, qlm, lane);
		break;
	case GSERN_CONFIG_QLM_TUNING_TX_MAIN:
	case GSERN_CONFIG_QLM_TUNING_TX_PRE:
	case GSERN_CONFIG_QLM_TUNING_TX_POST:
	case GSERN_CONFIG_QLM_TUNING_TX_BS:
		mode = va_arg(vl, char*);
		baud_mhz = va_arg(vl, int);
		qlm = va_arg(vl, int);
		lane = va_arg(vl, int);
		ret = gsern_config_get_qlm_tuning(
			prop, mode, baud_mhz, qlm, lane);
		break;
	case GSERN_CONFIG_QLM_VOLTAGE:
		ret = plat_octeontx_bcfg->qlm_voltage;
		break;
	default:
		WARN("Unknown property to read from BDK DT\n");
		ret = -1;
	}

	va_end(vl);
	return ret;
}

int gsern_init_pcie(int qlm, bool is_first_qlm, enum gsern_flags flags,
	enum gsern_lane_modes mode)
{
	return -1;
}

int gsern_init_sata_no_scc(int qlm, enum gsern_lane_modes mode)
{
	return -1;
}

int gsern_init_sata_scc(int qlm, enum gsern_lane_modes mode)
{
	return -1;
}
