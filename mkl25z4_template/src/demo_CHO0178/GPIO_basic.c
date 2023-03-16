#include "wdog.h"

__attribute__ ((weak)) int main(void)
{
	wdog_init(WDOG_CONF_LPOCLK_1024_CYCLES);

	// nastavte pin cervene led diody na

	while (1) {
		wdog_refresh();
	}

	return 0;
}

