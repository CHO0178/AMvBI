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

	// nastavte modulo hodnotu na PWM_PERIOD (kde vnikne problem?)

	// nastavte typ signálu na Edge-aligned PWM, High-true pulses

	// nastavte CMOD na 0b01 a delicku hodinoveho signalu na deleni dvemi (0b01)


	while(1)
	{
		uint16_t pot1Val = adc_bm_read(ADC_BM_MODE_8BIT_SE, ADC_CHAN_POT1);
		// nastavte hodnotu chanel value na hodnoutu získanou z potenciometru (0-255)

	}
}

	// otestujte a provedte zmenu pro opravu peaku na osciloskopu při zadani maximalni hodnoty

	// pridejte dalsi potenciometr a kanal stejneho casovace otestujte vztahy
	// mezi kanaly pri pouziti ruznych nastaveni registru CnSC
