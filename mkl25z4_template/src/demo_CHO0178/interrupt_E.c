#include "demo_CHO0178/littleHelper.h"
#include "MKL25Z4.h"
#include "wdog.h"
#include "led.h"
#include "btn.h"




void blockingFunctionExample();
void nonBlockingFunctionExample();

// CZ: vyzkousejte co se stane pokud pouzijete blokovací a neblokovaci funkce v
// ruznych kombinacich jako bezici funkci nebo preruseni a popiste jaky maji vliv
// EN: try different combination of functions as base function and interrupt
// function and describe what do you see


int main(void)
{
	wdog_init(WDOG_CONF_LPOCLK_1024_CYCLES);
	led_init();
	btn_init();

	// CZ: povol prijem preruseni pro port A a nastav prioritu na 2
	// EN: enable processing of incoming interrupt signal from port A and set
	// priority 2

	// CZ: povol generovani preruseni v periferii port A pro sestupnou i
	// nastupnou hranu
	// EN: enable generating interrupt signal in port A for falling and rising
	// edge

	while (1) {
		wdog_refresh();
		// CZ: zavolej funkci
		// EN: call function

	}

	return 0;
}

void PORTA_IRQHandler(void)
{
	// CZ: vynuluj flag
	// EN: reset flag

	// CZ: zavolej funkci
	// EN: call function

}


void blockingFunctionExample()
{
	//wait
	for(int i = 0;i<2000000;i++){}

	// CZ: zapni diodu 1 a vypni diodu 2
	// EN: turn on diode 1 and turn off diode 2

	//wait
	for(int i = 0;i<2000000;i++){}

	// CZ: zapni diodu 2 a vypni diodu 1
	// EN: turn on diode 2 and turn off diode 1


}

void nonBlockingFunctionExample()
{
	// CZ: pokud je tlacitko 2 sepnute rozsvit diodu 3
	// EN: if button 2 is pushed turn on diode 3

}


