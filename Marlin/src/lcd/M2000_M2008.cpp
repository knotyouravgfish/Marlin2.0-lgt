#include "../../inc/MarlinConfig.h"
#include "../gcode/gcode.h"

#if ENABLED(LGT_LCD_DW)
  #include "lgtdwlcd.h"
  #include "lgtdwdef.h"

  #include "../module/motion.h"
  #include "../feature/runout.h"
  // #include "../../module/stepper.h"
  // #include "../../module/endstops.h"

  // stop printing and return to home menu
  void GcodeSuite::M2000()
  {
      SERIAL_ECHOLNPGM("run M2000");
      relative_mode = false;
      M18_M84();
		  LGT_is_printing = false;
		  if (leveling_sta!=2)
		  {
			  lgtLcdDw.LGT_Change_Page(ID_MENU_HOME);
		  }
		  else
		  {
			  leveling_sta=0;
		  }
		  runout.reset();
  }

  // wait for printing pausing
  void GcodeSuite::M2001()
  {
      // LGT_Pause_Move();
		  // lgtLcdDw.LGT_Change_Page(ID_MENU_PRINT_HOME_PAUSE);
  }

  #if ENABLED(U20_PLUS)
  // wait for auto-levelling measuring 
    void GcodeSuite::M2002()
    {
		  planner.synchronize();
		  LGT_LCD.LGT_Change_Page(ID_MENU_MEASU_S1 + 1);
    }
  #endif

  // save position and filament runout  move
  void GcodeSuite::M2003()
  {
  }

  // load filament
  void GcodeSuite::M2004()
  {
    SERIAL_ECHOLNPGM("run M2004");
    lgtLcdDw.LGT_Change_Filament(LOAD_FILA_LEN);

  }

  // unload filament
  void GcodeSuite::M2005()
  {
    SERIAL_ECHOLNPGM("run M2005");
    lgtLcdDw.LGT_Change_Filament(UNLOAD_FILA_LEN);

  }

  // filament change in printing
  void GcodeSuite::M2006()
  {
  }

  void GcodeSuite::M2007()
  {
  }
#endif // LGT_LCD_DW
