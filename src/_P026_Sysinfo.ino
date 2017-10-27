//#######################################################################################################
//#################################### Plugin 026: System Info ##########################################
//#######################################################################################################

#define PLUGIN_026
#define PLUGIN_ID_026         26
#define PLUGIN_NAME_026       "System Info"
#define PLUGIN_VALUENAME1_026 ""

boolean Plugin_026(byte function, struct EventStruct *event, String& string)
{
  boolean success = false;
  double value = 0;
  // double v = sysTime - (Settings.TimeZone * 60) ;

  switch (function)
  {

    case PLUGIN_DEVICE_ADD:
      {
        Device[++deviceCount].Number = PLUGIN_ID_026;
        Device[deviceCount].VType = SENSOR_TYPE_SINGLE;
        Device[deviceCount].ValueCount = 1;
        Device[deviceCount].SendDataOption = true;
        Device[deviceCount].TimerOption = true;
        Device[deviceCount].FormulaOption = true;
        break;
      }

    case PLUGIN_GET_DEVICENAME:
      {
        string = F(PLUGIN_NAME_026);
        break;
      }

    case PLUGIN_GET_DEVICEVALUENAMES:
      {
        strcpy_P(ExtraTaskSettings.TaskDeviceValueNames[0], PSTR(PLUGIN_VALUENAME1_026));
        break;
      }

    case PLUGIN_WEBFORM_LOAD:
      {
        byte choice = Settings.TaskDevicePluginConfig[event->TaskIndex][0];
        String options[11];
        options[0] = F("Uptime");
        options[1] = F("Free RAM");
        options[2] = F("Wifi RSSI");
        options[3] = F("Input VCC");
        options[4] = F("System load");
        options[5] = F("IP 1.Octet");
        options[6] = F("IP 2.Octet");
        options[7] = F("IP 3.Octet");
        options[8] = F("IP 4.Octet");
        options[9] = F("DS3231 Temperature");
        options[10] = F("Date & Time Epoch");
        
        addFormSelector(string, F("Indicator"), F("plugin_026"), 11, options, NULL, choice);

        success = true;
        break;
      }

    case PLUGIN_WEBFORM_SAVE:
      {
        Settings.TaskDevicePluginConfig[event->TaskIndex][0] = getFormItemInt(F("plugin_026"));
        success = true;
        break;
      }

    case PLUGIN_READ:
      {
        
        switch(Settings.TaskDevicePluginConfig[event->TaskIndex][0])
        {
          case 0:
          {
            value = (wdcounter /2);
            break;
          }
          case 1:
          {
            value = ESP.getFreeHeap();
            break;
          }
          case 2:
          {
            value = WiFi.RSSI();
            break;
          }
          case 3:
          {
#if FEATURE_ADC_VCC
            value = vcc;
#else
            value = -1.0;
#endif
            break;
          }
          case 4:
          {
            value = (100 - (100 * loopCounterLast / loopCounterMax));
            break;
          }
          case 5:
          {
            value = WiFi.localIP()[0];
            break;
          }
          case 6:
          {
            value = WiFi.localIP()[1];
            break;
          }
          case 7:
          {
            value = WiFi.localIP()[2];
            break;
          }
          case 8:
          {
            value = WiFi.localIP()[3];
            break;
          }
          case 9:
          {
            if (RtcHardware == 3231){
              value = Rtc.GetTemperature().AsFloat();
            } else {
              value = 0;
            }
            break;
          }
          case 10:
          {
            value = sysTime - (Settings.TimeZone * 60); // Retorna sempre GMT para não confundir a galera
            break;
          }
        }

        // String log = F("SYS [");
        // log += sysTime;
        // log += ("] : ");
        // log += value;
        // addLog(LOG_LEVEL_INFO,log);

        UserVar[event->BaseVarIndex] = value;
        success = true;
        break;
      }
  }
  return success;
}
