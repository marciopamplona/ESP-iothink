//#######################################################################################################
//########################### Controller Plugin 006: PiDome MQTT ########################################
//#######################################################################################################

#define CPLUGIN_006
#define CPLUGIN_ID_006         6
#define CPLUGIN_NAME_006       "Generic MQTT"

boolean CPlugin_006(byte function, struct EventStruct *event, String& string)
{
  boolean success = false;

  switch (function)
  {
    case CPLUGIN_PROTOCOL_ADD:
      {
        Protocol[++protocolCount].Number = CPLUGIN_ID_006;
        Protocol[protocolCount].usesMQTT = true;
        Protocol[protocolCount].usesTemplate = true;
        Protocol[protocolCount].usesAccount = false;
        Protocol[protocolCount].usesPassword = false;
        Protocol[protocolCount].defaultPort = 1883;
        Protocol[protocolCount].usesID = false;
        break;
      }

    case CPLUGIN_GET_DEVICENAME:
      {
        string = F(CPLUGIN_NAME_006);
        break;
      }

    case CPLUGIN_PROTOCOL_TEMPLATE:
      {
        event->String1 = F("/Home/#");
        event->String2 = F("/hooks/devices/%id%/SensorData/%measuretag%");
        break;
      }

    case CPLUGIN_PROTOCOL_RECV:
      {
        // topic structure /Home/Floor/Location/device/<systemname>/gpio/16
        // Split topic into array
        String tmpTopic = event->String1.substring(1);
        String topicSplit[10];
        int SlashIndex = tmpTopic.indexOf('/');
        byte count = 0;
        while (SlashIndex > 0 && count < 10 - 1)
        {
          topicSplit[count] = tmpTopic.substring(0, SlashIndex);
          tmpTopic = tmpTopic.substring(SlashIndex + 1);
          SlashIndex = tmpTopic.indexOf('/');
          count++;
        }
        topicSplit[count] = tmpTopic;

        String name = topicSplit[4];
        String cmd = topicSplit[5];
        struct EventStruct TempEvent;
        TempEvent.Par1 = topicSplit[6].toInt();
        TempEvent.Par2 = 0;
        TempEvent.Par3 = 0;
        if (event->String2 == F("false") || event->String2 == F("true"))
        {
          if (event->String2 == F("true"))
            TempEvent.Par2 = 1;
        }
        else
          TempEvent.Par2 = event->String2.toFloat();
        if (name == Settings.Name)
        {
          PluginCall(PLUGIN_WRITE, &TempEvent, cmd);
        }
        break;
      }

    case CPLUGIN_PROTOCOL_SEND:
      {
        MQTTdirectSend(event);
        break;
      }
      return success;
  }
}
