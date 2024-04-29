/**
 * @brief lesson: analog to digital converter
 * try continuous measurement with single channel as polling
 * and two channels as blocking function
 * @author Ing. Jan Choutka
 * @date 24.04.2024
 * @version 1
 */
/*

ADC
	CFG1
		ADIV	// clk signal divider
		MODE	// N-bit translation
	SC1
		ADCH	// channel select
		COCO	// complete conversion flag
	SC3
		ADC0	// is continuous on one sample
	R			// result

PORT
	PCR
		MUX		// multiplexer
*/


#include "wdog.h"
#include "MKL25Z4.h"

#include "led.h"

void startContinuousMeasuring(uint32_t channel);
void setSingleTimeMeasurementOnTrigger();
int blockingMeasurementOfPotentiometer(int pot);
void nonBlockingSetOfLedBarGraphToValueFromADC();


__attribute__ ((weak)) int main(void)
{
	wdog_init(WDOG_CONF_DIS);
	led_init();
	// CZ: nastavte ADC
	// EN: initialize ADC

	//startContinuousMeasuring(0b1100); // 0b1011  0b1100
	setSingleTimeMeasurementOnTrigger();


	while (1) {
		// CZ: ziskejte hodnotu z potenciometru a nastavte bargraf
		// EN: get value from potentiometer and set bargraph to this value
		int val1 = blockingMeasurementOfPotentiometer(1);
		int val2 = blockingMeasurementOfPotentiometer(2);
		led_bgraph(((val1+val2)/2)* 0.035f);
		//nonBlockingSetOfLedBarGraphToValueFromADC();
	}
	return 0;
}


/**
 * @brief set ADC to continuous measuring and start measurement
 * @param channel value of channel connected to
 * potentiometer from refMan pg. 79
 */
void startContinuousMeasuring(uint32_t channel)
{
	// CZ: nastavte delicku hodinoveho signalu na 4 a 9-bitovou konverzi
	// EN: set divider of signal source to divide by 4 and 9-bit conversion
	ADC0->CFG1 = 0b10 << ADC_CFG1_ADIV_SHIFT;

	// CZ: nastavte ADC na kontinualni mereni
	// EN: set ADC continuous measurement
	ADC0->SC3 = ADC_SC3_ADCO_MASK;

	// CZ: trigrujte ADC kolnverzi na cahnnel
	// EN: trigger ADC conversion at channel
	ADC0->SC1[0] = channel;
}


/**
 * @brief set speed of conversion and stop continuous conversion
 */
void setSingleTimeMeasurementOnTrigger()
{
	// CZ: nastavte delicku hodinoveho signalu na 4 a 9-bitovou konverzi
	// EN: set divider of signal source to divide by 4 and 9-bit conversion
	ADC0->CFG1 = 0b10 << ADC_CFG1_ADIV_SHIFT;

	// CZ: nastavte
	// EN: set measurement to continuous measurement
	ADC0->SC3 &= ~ADC_SC3_ADCO_MASK;
}

/**
 * @brief trigger ADC measurement and wait till the measurement is done
 * then return measured value
 * @param pot number of potentiometer pot1 1 pot2 2
 * @return  value of potentiometer error -1 potentiometer not known
 */
int blockingMeasurementOfPotentiometer(int pot)
{
	// CZ: spustte mereni hodnoty na potenciometru
	// EN: trigger measuring of potentiometer voltage
	switch(pot)
	{
		case 1:
			// CZ: trigrujte kanal potenciometru 1
			// EN: trigger channel of potentiometer 1
			ADC0->SC1[0] = 0B1011;
			break;
		case 2:
			// CZ: trigrujte kanal potenciometru 2
			// EN: trigger channel of potentiometer 2
			ADC0->SC1[0] = 0b1100;
			break;
		default:
			// CZ: vratte chybovou hodnotu
			// EN: return error not existing potentiometer
			return -1;
			break;
	}
	// CZ: vyckejte na dokonceni konverze a zvednuti priznaku
	// EN: wait for complete conversion flag to rise to rise
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK)){}

	return ADC0->R[0];
}

void nonBlockingSetOfLedBarGraphToValueFromADC()
{
	// CZ: pote co je dokoncen prevod analogu na digital
	// nastavte bargraf podle prellozene hodnoty
	// EN: if conversion is complete set the bar graph
	// regarding received value
	if(ADC0->SC1[0] & ADC_SC1_COCO_MASK)
	{
		led_bgraph(ADC0->R[0u] * 0.035f);  //led_bgraph 0-8 diode
	}
}
