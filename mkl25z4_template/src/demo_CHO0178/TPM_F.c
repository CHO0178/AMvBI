/*

TPM(CH31)
	SC
	CNT
	MOD
	CnSC
	CnV
	STATUS
	CONF

*/

#include "soc_def.h"
#include "res_alloc.h"
#include "adc_bm.h"
#include "wdog.h"
#include "MKL25Z4.h"

#define PWM_PERIOD		255ul

void main()
{
	// nastavte mux pro výstup signálu na BNC konektor J12
	PORT_J12->PCR[IOIND_J12] = PORT_PCR_MUX(PORT_PCR_MUX_VAL_ALT3);

	// nastavte modulo hodnotu na PWM_PERIOD (kde vnikne problem?)
	TPM0->MOD = PWM_PERIOD - 1u;

	// nastavte typ signálu na Edge-aligned PWM, High-true pulses
	TPM0->CONTROLS[TPMCH_J12].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;

	// nastavte CMOD na 0b01 a delicku hodinoveho signalu na deleni dvemi (0b01)
	TPM0->SC = TPM_SC_CMOD(TPM_SC_CMOD_VAL_INTCLK) | TPM_SC_PS(TPM_SC_PS_VAL_D2);



	while(1)
	{
		uint16_t pot1Val = adc_bm_read(ADC_BM_MODE_8BIT_SE, ADC_CHAN_POT1);
		// nastavte hodnotu chanel value na hodnoutu získanou z potenciometru (0-255)
		TPM0->CONTROLS[TPMCH_J12].CnV = pot1Val;
	}
}
