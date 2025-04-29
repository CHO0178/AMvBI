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
		ADCH	// channel select (trigger)
		COCO	// complete conversion flag
		DIFF	// differential mode of measurement
	SC3
		ADCO	// is continuous on one sample
	R			// result

PORT
	PCR
		MUX		// multiplexer
*/


#include "wdog.h"
#include "MKL25Z4.h"

#include "led.h"

void exercise1();
void exercise2();
void exercise3();
void startContinuousMeasuring(int pot);
void setSingleTimeMeasurementOnTrigger();
int blockingMeasurementOfPotentiometer(int pot);
int nonBlockingGetADCval();


__attribute__ ((weak)) int main(void)
{
	wdog_init(WDOG_CONF_DIS);
	led_init();
	// CZ: zavolejte cviceni
	// EN: call exercize
	exercise1();
	return 0;
}


/**
 * @brief set ADC to continuous measuring and start measurement
 * @param channel value "ADC channel" of channel connected to
 * potentiometer (refMan pg. 79)
 */
void startContinuousMeasuring(int pot)
{
	// CZ: nastavte delicku hodinoveho signalu na 4 a 8-bitovou konverzi
	// EN: set divider of signal source to divide by 4 and 8-bit conversion


	// CZ: nastavte ADC na kontinualni mereni
	// EN: set ADC continuous measurement


	// CZ: trigrujte ADC kolnverzi zmennou kanalu
	// EN: trigger ADC conversion at channel


}


/**
 * @brief set speed of conversion and stop continuous conversion
 */
void setSingleTimeMeasurementOnTrigger()
{
	// CZ: nastavte delicku hodinoveho signalu na 4 a 8-bitovou konverzi
	// EN: set divider of signal source to divide by 4 and 8-bit conversion


	// CZ: nastavte mereni na kontinnualni
	// EN: set measurement to continuous measurement

}

/**
 * @brief trigger ADC measurement and wait till the measurement is done
 * then return measured value
 * @param pot number of potentiometer pot1 1 pot2 2
 * @return  value of potentiometer error -1 potentiometer not known
 */
int blockingMeasurementOfPotentiometer(int pot)
{
	int result;
	// CZ: spustte mereni hodnoty na potenciometru
	// EN: trigger measuring of potentiometer voltage

	// CZ: vyckejte na dokonceni konverze a zvednuti priznaku preruseni
	// EN: wait for complete conversion flag to rise to rise



	return result;
}

/**
 * @brief capture and return value of analog signal
 */
int nonBlockingGetADCval()
{
	// CZ: pote co je dokoncen prevod analogu na digital
	// nastavte vratte jeho hodnotu jinak -1
	// EN: if conversion is complete return result else -1


	return -1;
}

/**
 * @brief
 * 	CZ: vyuzije mereni s trigrovanim pred kazdym prevodem a vykreslete
 * 	hodnotu potenciometru na bargraf vzdy po dokonceni prevodu
 * 	EN: trigger ADC before every measurement and plot result after
 * 	converison is completed
 */
void exercise1(){
	int val;
	// CZ: zavolejte funkci pro nastaveni ADC
	// EN: call initialize ADC
	setSingleTimeMeasurementOnTrigger();

	while (1) {
		// CZ: ziskejte hodnotu z potenciometru a nastavte bargraf
		// EN: get value from potentiometer and set bargraph to this value
		val = blockingMeasurementOfPotentiometer(1);
		led_bindisp(val);
	}
}

/**
 * @brief
 * 	CZ: vyuzije kontunualni mereni a vykresluje
 * hodnotu potenciometru na bargraf vzdy po dokonceni prevodu
 * 	EN: using continuous measurement and displaying the status
 * of the potentiometer on the bargraph immediately after the
 * conversion is completed.
 */
void exercise2(){
	int val;

	// CZ: zavolejte funkci pro nastaveni ADC
	// EN: call initialize ADC
	startContinuousMeasuring(2);
	while (1) {
		// CZ: pokud je navracena hodnota vetsi nebo rovno 0 vykresli na bargraf
		// EN: get value from potentiometer and set bargraph to this value
		val = nonBlockingGetADCval();
		if(val>=0)
		{
			led_bindisp(val);
		}
	}
}

/**
 * @brief
 * 	CZ: funkce secte hodnoty obou potenciometru a vykresli na bargraf.
 * 	maximalni hodnota je soucet obou maxim potenciometru
 * 	EN: function add values of both potentiometers and show result on
 * 	bargraph sum of both value is maximum of both potentiometers maxims
 */
void exercise3(){

	// CZ: zavolejte funkci pro nastaveni ADC
	// EN: call initialize ADC


	while (1) {
		// CZ: ziskejte hodnotu z potenciometru a nastavte bargraf
		// EN: get value from potentiometer and set bargraph to this value

	}
}


