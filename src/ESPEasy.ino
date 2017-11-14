//   Esquema de ligação:
//   =================================================================================
//
//   SD card (SPI):         RTC (I2C):      DEEP SLEEP WAKEUP:
//   ==============         ==========      ==================
//   CS:   D3 ou D8         SDA: D2         D0 -> RST
//   MISO: D6               SCL: D1
//   MOSI: D7               
//   SCK:  D5
//   
//   =================================================================================
//   Simple Arduino sketch for ESP module, supporting:
//   =================================================================================
//   Simple switch inputs and direct GPIO output control to drive relais, mosfets, etc
//   Analog input (ESP-7/12 only)
//   Pulse counters
//   Dallas OneWire DS18b20 temperature sensors
//   DHT11/22/12 humidity sensors
//   BMP085 I2C Barometric Pressure sensor
//   PCF8591 4 port Analog to Digital converter (I2C)
//   RFID Wiegand-26 reader
//   MCP23017 I2C IO Expanders
//   BH1750 I2C Luminosity sensor
//   Arduino Pro Mini with IO extender sketch, connected through I2C
//   LCD I2C display 4x20 chars
//   HC-SR04 Ultrasonic distance sensor
//   SI7021 I2C temperature/humidity sensors
//   TSL2561 I2C Luminosity sensor
//   TSOP4838 IR receiver
//   PN532 RFID reader
//   Sharp GP2Y10 dust sensor
//   PCF8574 I2C IO Expanders
//   PCA9685 I2C 16 channel PWM driver
//   OLED I2C display with SSD1306 driver
//   MLX90614 I2C IR temperature sensor
//   ADS1115 I2C ADC
//   INA219 I2C voltage/current sensor
//   BME280 I2C temp/hum/baro sensor
//   MSP5611 I2C temp/baro sensor
//   BMP280 I2C Barometric Pressure sensor
//   SHT1X temperature/humidity sensors
//   Ser2Net server

// ********************************************************************************
//   User specific configuration
// ********************************************************************************

// Set default configuration settings if you want (not mandatory)
// You can always change these during runtime and save to eeprom
// After loading firmware, issue a 'reset' command to load the defaults.

#define DEFAULT_NAME        "Desto000X"         // Enter your device friendly name
#define DEFAULT_SSID        "IO_think"          // Enter your network SSID
#define DEFAULT_KEY         "19092017"            // Enter your network WPA key
#define DEFAULT_DELAY       1                  // Enter your Send delay in seconds
#define DEFAULT_AP_KEY      "configesp"         // Enter network WPA key for AP (config) mode

#define DEFAULT_USE_STATIC_IP   false           // true or false enabled or disabled set static IP
#define DEFAULT_IP          "192.168.0.50"      // Enter your IP address
#define DEFAULT_DNS         "192.168.0.1"       // Enter your DNS
#define DEFAULT_GW          "192.168.0.1"       // Enter your gateway
#define DEFAULT_SUBNET      "255.255.255.0"     // Enter your subnet

#define DEFAULT_CONTROLLER   true              // true or false enabled or disabled, set 1st controller defaults
// using a default template, you also need to set a DEFAULT PROTOCOL to a suitable MQTT protocol !
#define DEFAULT_SUB         "/%chipid%/write/#" // Enter your sub
#define DEFAULT_PUB         "/%chipid%/%systime%/%sensortag%/%measuretag%" // Enter your pub
#define DEFAULT_SERVER      "192.168.1.20"      // Enter your Server IP address
#define DEFAULT_PORT        1883                // Enter your Server port value

#define DEFAULT_PROTOCOL    6                   // Protocol used for controller communications
//   1 = Domoticz HTTP
//   2 = Domoticz MQTT
//   3 = Nodo Telnet
//   4 = ThingSpeak
//   5 = OpenHAB MQTT
//   6 = PiDome MQTT
//   7 = EmonCMS
//   8 = Generic HTTP
//   9 = FHEM HTTP

#define UNIT                0

// Enable FEATURE_ADC_VCC to measure supply voltage using the analog pin
// Please note that the TOUT pin has to be disconnected in this mode
// Use the "System Info" device to read the VCC value
#define FEATURE_ADC_VCC                  false

//enable mDNS mode (adds about 6kb ram and some bytes IRAM)
//#define FEATURE_MDNS

//Select which plugin sets you want to build.
//These are normally automaticly set via the Platformio build environment.
//If you use ArduinoIDE you might need to uncomment some of them, depending on your needs
//If you dont select any, a version with a minimal number of plugins will be biult for 512k versions.
//(512k is NOT finsihed or tested yet as of v2.0.0-dev6)

//build all the normal stable plugins
//#define PLUGIN_BUILD_NORMAL

//build all plugins that are in test stadium
//#define PLUGIN_BUILD_TESTING

//build all plugins that still are being developed and are broken or incomplete
//#define PLUGIN_BUILD_DEV

// ********************************************************************************
//   DO NOT CHANGE ANYTHING BELOW THIS LINE
// ********************************************************************************
#define ESP_PROJECT_PID             20171113L
#define VERSION                             8
#define BUILD                           20000 // git version 2.0.0
#define BUILD_NOTES                 " - Iothink"

#ifndef BUILD_GIT
  #define BUILD_GIT "(custom)"
#endif

#define MAX_FLASHWRITES_PER_DAY          1000 // per 24 hour window

#define NODE_TYPE_ID_ESP_EASY_STD           1
#define NODE_TYPE_ID_ESP_EASYM_STD         17
#define NODE_TYPE_ID_ESP_EASY32_STD        33
#define NODE_TYPE_ID_ARDUINO_EASY_STD      65
#define NODE_TYPE_ID_NANO_EASY_STD         81
#define NODE_TYPE_ID                        NODE_TYPE_ID_ESP_EASYM_STD

#define PLUGIN_INIT_ALL                     1
#define PLUGIN_INIT                         2
#define PLUGIN_READ                         3
#define PLUGIN_ONCE_A_SECOND                4
#define PLUGIN_TEN_PER_SECOND               5
#define PLUGIN_DEVICE_ADD                   6
#define PLUGIN_EVENTLIST_ADD                7
#define PLUGIN_WEBFORM_SAVE                 8
#define PLUGIN_WEBFORM_LOAD                 9
#define PLUGIN_WEBFORM_SHOW_VALUES         10
#define PLUGIN_GET_DEVICENAME              11
#define PLUGIN_GET_DEVICEVALUENAMES        12
#define PLUGIN_WRITE                       13
#define PLUGIN_EVENT_OUT                   14
#define PLUGIN_WEBFORM_SHOW_CONFIG         15
#define PLUGIN_SERIAL_IN                   16
#define PLUGIN_UDP_IN                      17
#define PLUGIN_CLOCK_IN                    18
#define PLUGIN_TIMER_IN                    19
#define PLUGIN_FIFTY_PER_SECOND            20
#define PLUGIN_SET_CONFIG                  21
#define PLUGIN_GET_DEVICEGPIONAMES         22
#define PLUGIN_EXIT                        23
#define PLUGIN_GET_CONFIG                  24

#define CPLUGIN_PROTOCOL_ADD                1
#define CPLUGIN_PROTOCOL_TEMPLATE           2
#define CPLUGIN_PROTOCOL_SEND               3
#define CPLUGIN_PROTOCOL_RECV               4
#define CPLUGIN_GET_DEVICENAME              5
#define CPLUGIN_WEBFORM_SAVE                6
#define CPLUGIN_WEBFORM_LOAD                7

#define LOG_LEVEL_ERROR                     1
#define LOG_LEVEL_INFO                      2
#define LOG_LEVEL_DEBUG                     3
#define LOG_LEVEL_DEBUG_MORE                4
#define LOG_LEVEL_DEBUG_DEV                 9 // use for testing/debugging only, not for regular use

#define CMD_REBOOT                         89
#define CMD_WIFI_DISCONNECT               135

#if defined(PLUGIN_BUILD_TESTING) || defined(PLUGIN_BUILD_DEV)
  #define DEVICES_MAX                      72
#else
  #define DEVICES_MAX                      64
#endif
#define TASKS_MAX                           8 // max 12!
#define CONTROLLER_MAX                      1 // max 4!
#define VARS_PER_TASK                       4
#define PLUGIN_MAX                DEVICES_MAX
#define PLUGIN_CONFIGVAR_MAX                8
#define PLUGIN_CONFIGFLOATVAR_MAX           4
#define PLUGIN_CONFIGLONGVAR_MAX            4
#define PLUGIN_EXTRACONFIGVAR_MAX          16
#define CPLUGIN_MAX                        16
#define UNIT_MAX                           32 // Only relevant for UDP unicast message 'sweeps' and the nodelist.
#define RULES_TIMER_MAX                     8
#define SYSTEM_TIMER_MAX                    8
#define SYSTEM_CMD_TIMER_MAX                2
#define PINSTATE_TABLE_MAX                 32
#define RULES_MAX_SIZE                   2048
#define RULES_MAX_NESTING_LEVEL             3
#define RULESETS_MAX                        4

#define PIN_MODE_UNDEFINED                  0
#define PIN_MODE_INPUT                      1
#define PIN_MODE_OUTPUT                     2
#define PIN_MODE_PWM                        3
#define PIN_MODE_SERVO                      4

#define SEARCH_PIN_STATE                 true
#define NO_SEARCH_PIN_STATE             false

#define DEVICE_TYPE_SINGLE                  1  // connected through 1 datapin
#define DEVICE_TYPE_DUAL                    2  // connected through 2 datapins
#define DEVICE_TYPE_TRIPLE                  3  // connected through 3 datapins
#define DEVICE_TYPE_ANALOG                 10  // AIN/tout pin
#define DEVICE_TYPE_I2C                    20  // connected through I2C
#define DEVICE_TYPE_DUMMY                  99  // Dummy device, has no physical connection

#define SENSOR_TYPE_SINGLE                  1
#define SENSOR_TYPE_TEMP_HUM                2
#define SENSOR_TYPE_TEMP_BARO               3
#define SENSOR_TYPE_TEMP_HUM_BARO           4
#define SENSOR_TYPE_DUAL                    5
#define SENSOR_TYPE_TRIPLE                  6
#define SENSOR_TYPE_QUAD                    7
#define SENSOR_TYPE_SWITCH                 10
#define SENSOR_TYPE_DIMMER                 11
#define SENSOR_TYPE_LONG                   20
#define SENSOR_TYPE_WIND                   21

#define VALUE_SOURCE_SYSTEM                 1
#define VALUE_SOURCE_SERIAL                 2
#define VALUE_SOURCE_HTTP                   3
#define VALUE_SOURCE_MQTT                   4
#define VALUE_SOURCE_UDP                    5

#define BOOT_CAUSE_MANUAL_REBOOT            0
#define BOOT_CAUSE_COLD_BOOT                1
#define BOOT_CAUSE_DEEP_SLEEP               2
#define BOOT_CAUSE_EXT_WD                  10

#define DAT_TASKS_SIZE                   2048
#define DAT_TASKS_CUSTOM_OFFSET          1024
#define DAT_CUSTOM_CONTROLLER_SIZE       1024
#define DAT_CONTROLLER_SIZE              1024

#include "lwip/tcp_impl.h"
#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
#include <DNSServer.h>
#include <WiFiUdp.h>
#include <ESP8266WebServer.h>

#ifdef FEATURE_MDNS
#include <ESP8266mDNS.h>
#endif

#include <Wire.h>
#include <SPI.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
// #include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define FS_NO_GLOBALS
#include <FS.h>
//#include <SD.h>
#include <SdFat.h>
SdFat SD;
boolean sdcardEnabled = false;
#include <base64.h>

#if FEATURE_ADC_VCC
  ADC_MODE(ADC_VCC);
#endif

#ifndef LWIP_OPEN_SRC
  #define LWIP_OPEN_SRC
#endif

#include "lwip/opt.h"
#include "lwip/udp.h"
#include "lwip/igmp.h"
#include "include/UdpContext.h"
#include "limits.h"

extern "C" {
#include "user_interface.h"
}

// RTC stuff
#define countof(a) (sizeof(a) / sizeof(a[0]))
boolean lostPower;
#include <RtcDS3231.h>
#include <RtcDS1307.h>
int RtcHardware = 0;
RtcDS3231<TwoWire> Rtc(Wire);

#include "shortFixedPoint.h"

// Setup DNS, only used if the ESP has no valid WiFi config
const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 4, 1);
DNSServer dnsServer;
#ifdef FEATURE_MDNS
MDNSResponder mdns;
#endif

// MQTT client
WiFiClient mqtt;
PubSubClient MQTTclient(mqtt);

// WebServer
ESP8266WebServer WebServer(80);

// udp protocol stuff (syslog, global sync, node info list, ntp time)
WiFiUDP portUDP;


extern "C" {
#include "spi_flash.h"
}
extern "C" uint32_t _SPIFFS_start;
extern "C" uint32_t _SPIFFS_end;
extern "C" uint32_t _SPIFFS_page;
extern "C" uint32_t _SPIFFS_block;

struct SecurityStruct
{
  char          WifiSSID[32];
  char          WifiKey[64];
  char          WifiSSID2[32];
  char          WifiKey2[64];
  char          lastWifiSSID[32];
  char          lastWifiKey[64];
  char          WifiAPKey[64];
  char          ControllerUser[CONTROLLER_MAX][26];
  char          ControllerPassword[CONTROLLER_MAX][64];
  char          Password[26];
  //its safe to extend this struct, up to 4096 bytes, default values in config are 0
} SecuritySettings;

struct SettingsStruct
{
  unsigned long PID;
  int           Version;
  int16_t       Build;
  byte          IP[4];
  byte          Gateway[4];
  byte          Subnet[4];
  byte          DNS[4];
  byte          IP_Octet;
  byte          Unit;
  char          Name[26];
  char          NTPHost[64];
  unsigned long Delay;
  int8_t        Pin_i2c_sda;
  int8_t        Pin_i2c_scl;
  int8_t        Pin_status_led;
  int8_t        Pin_sd_cs;
  int8_t        PinBootStates[17];
  byte          Syslog_IP[4];
  unsigned int  UDPPort;
  byte          SyslogLevel;
  byte          SerialLogLevel;
  byte          WebLogLevel;
  byte          SDLogLevel;
  unsigned long BaudRate;
  unsigned long MessageDelay;
  byte          deepSleep;
  boolean       CustomCSS;
  boolean       DST;
  byte          WDI2CAddress;
  boolean       UseRules;
  boolean       UseSerial;
  boolean       UseSSDP;
  boolean       UseNTP;
  unsigned long WireClockStretchLimit;
  boolean       GlobalSync;
  unsigned long ConnectionFailuresThreshold;
  int16_t       TimeZone;
  boolean       MQTTRetainFlag;
  boolean       InitSPI;
  byte          Protocol[CONTROLLER_MAX];
  byte          TaskDeviceNumber[TASKS_MAX];
  unsigned int  OLD_TaskDeviceID[TASKS_MAX];
  union {
    struct {
      int8_t        TaskDevicePin1[TASKS_MAX];
      int8_t        TaskDevicePin2[TASKS_MAX];
      int8_t        TaskDevicePin3[TASKS_MAX];
      byte          TaskDevicePort[TASKS_MAX];
    };
    int8_t        TaskDevicePin[4][TASKS_MAX];
  };
  boolean       TaskDevicePin1PullUp[TASKS_MAX];
  int16_t       TaskDevicePluginConfig[TASKS_MAX][PLUGIN_CONFIGVAR_MAX];
  boolean       TaskDevicePin1Inversed[TASKS_MAX];
  float         TaskDevicePluginConfigFloat[TASKS_MAX][PLUGIN_CONFIGFLOATVAR_MAX];
  long          TaskDevicePluginConfigLong[TASKS_MAX][PLUGIN_CONFIGLONGVAR_MAX];
  boolean       OLD_TaskDeviceSendData[TASKS_MAX];
  boolean       TaskDeviceGlobalSync[TASKS_MAX];
  byte          TaskDeviceDataFeed[TASKS_MAX];
  unsigned long TaskDeviceTimer[TASKS_MAX];
  boolean       TaskDeviceEnabled[TASKS_MAX];
  boolean       ControllerEnabled[CONTROLLER_MAX];
  unsigned int  TaskDeviceID[CONTROLLER_MAX][TASKS_MAX];
  boolean       TaskDeviceSendData[CONTROLLER_MAX][TASKS_MAX];
  boolean       Pin_status_led_Inversed;
  boolean       deepSleepOnFail;
  boolean       UseValueLogger;
  boolean       htpEnable;
  char          htpHost[64];
  uint32_t      syncInterval;
  int8_t        samplesPerTx;
  boolean       sdcardMQTTlogger;
  //its safe to extend this struct, up to several bytes, default values in config are 0
  //look in misc.ino how config.dat is used because also other stuff is stored in it at different offsets.
  //TODO: document config.dat somewhere here
} Settings;

struct ControllerSettingsStruct
{
  boolean       UseDNS;
  byte          IP[4];
  unsigned int  Port;
  char          HostName[65];
  char          Publish[129];
  char          Subscribe[129];
};

struct ExtraTaskSettingsStruct
{
  byte    TaskIndex;
  char    TaskDeviceName[41];
  char    TaskDeviceFormula[VARS_PER_TASK][41];
  char    TaskDeviceValueNames[VARS_PER_TASK][41];
  long    TaskDevicePluginConfigLong[PLUGIN_EXTRACONFIGVAR_MAX];
  byte    TaskDeviceValueDecimals[VARS_PER_TASK];
  int16_t TaskDevicePluginConfig[PLUGIN_EXTRACONFIGVAR_MAX];
} ExtraTaskSettings;

struct EventStruct
{
  byte Source;
  byte TaskIndex; // index position in TaskSettings array, 0-11
  byte ControllerIndex; // index position in Settings.Controller, 0-3
  byte ProtocolIndex; // index position in protocol array, depending on which controller plugins are loaded.
  byte BaseVarIndex;
  int idx;
  byte sensorType;
  int Par1;
  int Par2;
  int Par3;
  int Par4;
  int Par5;
  byte OriginTaskIndex;
  String String1;
  String String2;
  String String3;
  byte *Data;
};

struct LogStruct
{
  unsigned long timeStamp;
  char* Message;
} Logging[10];
int logcount = -1;

struct DeviceStruct
{
  byte Number;
  byte Type;
  byte VType;
  byte Ports;
  boolean PullUpOption;
  boolean InverseLogicOption;
  boolean FormulaOption;
  byte ValueCount;
  boolean Custom;
  boolean SendDataOption;
  boolean GlobalSyncOption;
  boolean TimerOption;
  boolean TimerOptional;
  boolean DecimalsOnly;
} Device[DEVICES_MAX + 1]; // 1 more because first device is empty device

struct ProtocolStruct
{
  byte Number;
  boolean usesMQTT;
  boolean usesAccount;
  boolean usesPassword;
  int defaultPort;
  boolean usesTemplate;
  boolean usesID;
} Protocol[CPLUGIN_MAX];

struct NodeStruct
{
  byte ip[4];
  byte age;
  uint16_t build;
  char* nodeName;
  byte nodeType;
} Nodes[UNIT_MAX];

struct systemTimerStruct
{
  unsigned long timer;
  byte plugin;
  byte Par1;
  byte Par2;
  byte Par3;
} systemTimers[SYSTEM_TIMER_MAX];

struct systemCMDTimerStruct
{
  unsigned long timer;
  String action;
} systemCMDTimers[SYSTEM_CMD_TIMER_MAX];

struct pinStatesStruct
{
  byte plugin;
  byte index;
  byte mode;
  uint16_t value;
} pinStates[PINSTATE_TABLE_MAX];


// this offsets are in blocks, bytes = blocks * 4
#define RTC_BASE_STRUCT 64
#define RTC_BASE_USERVAR 74

//max 40 bytes: ( 74 - 64 ) * 4
struct RTCStruct
{
  byte ID1;
  byte ID2;
  boolean unused1;
  byte factoryResetCounter;
  byte deepSleepState;
  byte unused2;
  byte flashDayCounter;
  unsigned long flashCounter;
  unsigned long bootCounter;
  unsigned long readCounter;
  unsigned long syncCounter;
  unsigned long nextSyncTime;
  unsigned long seekPosition;
} RTC;

int deviceCount = -1;
int protocolCount = -1;

boolean printToWeb = false;
String printWebString = "";
boolean printToWebJSON = false;

// float UserVar[VARS_PER_TASK * TASKS_MAX];
double UserVar[VARS_PER_TASK * TASKS_MAX];
unsigned long RulesTimer[RULES_TIMER_MAX];

unsigned long timerSensor[TASKS_MAX];
unsigned long timer100ms;
unsigned long timer20ms;
unsigned long timer1s;
unsigned long timerwd;
unsigned long lastSend;
unsigned int NC_Count = 0;
unsigned int C_Count = 0;
byte cmd_within_mainloop = 0;
unsigned long connectionFailures;
unsigned long wdcounter = 0;
unsigned long timerAPoff = 0;

#if FEATURE_ADC_VCC
float vcc = -1.0;
#endif

boolean WebLoggedIn = false;
int WebLoggedInTimer = 300;

boolean (*Plugin_ptr[PLUGIN_MAX])(byte, struct EventStruct*, String&);
byte Plugin_id[PLUGIN_MAX];

boolean (*CPlugin_ptr[CPLUGIN_MAX])(byte, struct EventStruct*, String&);
byte CPlugin_id[CPLUGIN_MAX];

String dummyString = "";

byte lastBootCause = BOOT_CAUSE_MANUAL_REBOOT;

boolean wifiSetup = false;
boolean wifiSetupConnect = false;

unsigned long start = 0;
unsigned long elapsed = 0;
unsigned long loopCounter = 0;
unsigned long loopCounterLast = 0;
unsigned long loopCounterMax = 1;
unsigned long dailyResetCounter = 0;

String eventBuffer = "";

uint16_t lowestRAM = 0;
String lowestRAMfunction = "";


// Compile time
RtcDateTime compileTime = RtcDateTime(__DATE__, __TIME__);
unsigned long clockCompare = compileTime.Epoch32Time();
uint32_t sysTime = 0;
uint32_t sysTimeGMT = 0;

boolean TxData = false;
boolean logData = true;

class __FlashStringHelper;
#define FPSTR(pstr_pointer) (reinterpret_cast<const __FlashStringHelper *>(pstr_pointer))
#define F(string_literal) (FPSTR(PSTR(string_literal)))


// 8 bytes
// Union: manobra para driblar o padding
struct memLogStruct {
  union {
    short IndexValue[2]; // 0 = index : 1 = value
    uint8_t byteIndex[4];
  };
  uint32_t epoch;
};

boolean WebServerInitialized = false;
boolean MQTTconnected = false;
boolean NextWakeRadioOn = true;
unsigned long freeSpace = 0;

#undef DEBUG_WIFI

/*********************************************************************************************\
 * SETUP
\*********************************************************************************************/
void setup()
{
  lowestRAM = FreeMem();

  Serial.begin(115200);
  Serial.print("\n\n\nBOOT\n\n\n");

  initLog();

  if (SpiffsSectors() < 32)
  {
    Serial.println(F("\nNo (or too small) SPIFFS area..\nSystem Halted\nPlease reflash with 128k SPIFFS minimum!"));
    while (true)
      delay(1);
  }

  emergencyReset();

  String log = F("\n\n\n\rINIT : Booting version: ");
  log += BUILD_GIT;
  addLog(LOG_LEVEL_INFO, log);
  addLog(LOG_LEVEL_INFO, String(F("INIT: Compile time "))+getDateTimeStringN(compileTime));

  // memLogStruct tt;
  // byte byteread = 0;
  // byte *byteBuf = (byte*)&tt;
  // char hexvalue[3]={0};
  // tt.byteIndex[0] = 0x01;
  // tt.byteIndex[1] = 0x02;
  // tt.epoch = 0x03040506;
  // tt.IndexValue[1] = 0x0708;

  // addLog(LOG_LEVEL_INFO, String(F("TESTE: "))+String(sizeof(SettingsStruct)));
  
  // for (int i=0; i<sizeof(memLogStruct); i++){
  //   byteread = *(byteBuf+i);
  //   sprintf(hexvalue, "%02X ",byteread);
  //   addLog(LOG_LEVEL_INFO, String(hexvalue)+" ");
  // }

  //warm boot
  if (readFromRTC())
  {
    RTC.bootCounter++;
    readUserVarFromRTC();

    if (RTC.deepSleepState == 1)
    {
      log = F("INIT : Rebooted from deepsleep #");
      lastBootCause=BOOT_CAUSE_DEEP_SLEEP;
    }
    else {
      log = F("INIT : Warm boot #");
      // Zera contador de leituras se não acordou do sleep
      RTC.readCounter = 0;
      delay(3000); // Delay para debug 
    }

    log += RTC.bootCounter;

  }
  //cold boot (RTC memory empty)
  else
  {
    initRTC();

    // cold boot situation
    if (lastBootCause == BOOT_CAUSE_MANUAL_REBOOT) // only set this if not set earlier during boot stage.
      lastBootCause = BOOT_CAUSE_COLD_BOOT;
    log = F("INIT : Cold Boot");
    delay(3000); // Delay para debug 
  }
  addLog(LOG_LEVEL_INFO, log);

  RTC.deepSleepState=0;
  saveToRTC();

  fileSystemCheck();
  LoadSettings();

  Settings.UseRules = 0;
  if (Settings.samplesPerTx == 0){
    Settings.samplesPerTx = 3;
    SaveSettings();
  }

  if (strcasecmp(SecuritySettings.WifiSSID, "ssid") == 0) wifiSetup = true;

  ExtraTaskSettings.TaskIndex = 255; // make sure this is an unused nr to prevent cache load on boot

  // if different version, eeprom settings structure has changed. Full Reset needed
  // on a fresh ESP module eeprom values are set to 255. Version results into -1 (signed int)
  if (Settings.Version != VERSION || Settings.PID != ESP_PROJECT_PID)
  {
    // Direct Serial is allowed here, since this is only an emergency task.
    Serial.print(F("\nPID:"));
    Serial.println(Settings.PID);
    Serial.print(F("Version:"));
    Serial.println(Settings.Version);
    Serial.println(F("INIT : Incorrect PID or version!"));
    delay(1000);
    ResetFactory();
  }

  if (Settings.UseSerial)
  {
    //make sure previous serial buffers are flushed before resetting baudrate
    Serial.flush();
    Serial.begin(Settings.BaudRate);
  }

  if (Settings.Build != BUILD) BuildFixes();

  log = F("INIT : Free RAM:");
  log += FreeMem();
  addLog(LOG_LEVEL_INFO, log);

  if (Settings.UseSerial && Settings.SerialLogLevel >= LOG_LEVEL_DEBUG_MORE) Serial.setDebugOutput(true);

  hardwareInit();

  log = F("INIT: free space for data logging: ");
  log += String(freeSpace)+F(" bytes");
  addLog(LOG_LEVEL_INFO, log);

  log = "INIT: Reading Counter: ";
  log += RTC.readCounter;
  log += " - Sync Counter: ";
  log += RTC.syncCounter;
  log += " - Unsent filesize: ";

  if (sdcardEnabled){
    log += String(unsentFileSize(false));
  } else {
    log += String(unsentFileSize(true));
  }
  addLog(LOG_LEVEL_INFO, log);

/////////////////////////////////////// RTC CHECKS

  log = F("INIT: reg 0x7, dev 0x68: ");
  log += readI2Cregister(7, DS1307_ADDRESS);
  
  addLog(LOG_LEVEL_DEBUG, log);
  byte reg = readI2Cregister(7, DS3231_ADDRESS);
  boolean presence = checkI2Cpresence(DS3231_ADDRESS);

  if (presence && ((reg & 0x6f)==3)){
    log = F("INIT: DS1307 detected");
    RtcDS1307<TwoWire> Rtc(Wire);
    RtcHardware = 1307;
  } else if (presence){
    log = F("INIT: DS3231 detected");
    RtcHardware = 3231;
  } else {
    log = F("INIT: no physical RTC detected");
  }

  addLog(LOG_LEVEL_INFO, log);

  if (RtcHardware) {

    Rtc.Begin();
    
    RtcDateTime now = Rtc.GetDateTime();

    log = F("DATE_TIME: ");
    log += getDateTimeStringN(now);

    if (!Rtc.IsDateTimeValid()) 
    {
        log += " -> RTC lost confidence in the DateTime!";
        //Rtc.SetDateTime(compileTime);
        lostPower = true;
    }
      if (!Rtc.GetIsRunning())
    {
        log += " -> RTC was not actively running, starting now";
        Rtc.SetIsRunning(true);
    }
    
    if (now < compileTime) 
    {
        log += " -> RTC is older than compile time!";
        //Rtc.SetDateTime(compileTime);
        lostPower = true;
    }

    if (RtcHardware == 3231){
      Rtc.Enable32kHzPin(false);
      Rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone);   log += "  --  INTERNAL TEMP: ";
      log += Rtc.GetTemperature().AsFloat();
      log += "C";
    }

    addLog(LOG_LEVEL_INFO, log);
  }
//////////////////////////////////////////////
  
  // Em modo Deep Sleep, o Radio é desligado por default
  if (isDeepSleepEnabled()){
    NextWakeRadioOn = false;
  }

  // Só loga e transmite se estiver sincronizado
  // if (RTC.syncCounter == 0){
    // Verifica se pode transmitir, resultado é múltiplo do samplesPerTx
    addLog(LOG_LEVEL_DEBUG, String(F("INIT: samplesPerTx: "))+String(Settings.samplesPerTx));
    if ((RTC.readCounter % Settings.samplesPerTx)==0){
      TxData = true;
      logData = false;
      addLog(LOG_LEVEL_DEBUG, F("INIT: data transmission CYCLE"));
    } else {
      TxData = false;
      logData = true;
      addLog(LOG_LEVEL_DEBUG, F("INIT: log data CYCLE"));
    }
    // Verifica se no próximo Wake, deve iniciar com o rádio ligado
    if (((RTC.readCounter+1) % Settings.samplesPerTx)==0){
      NextWakeRadioOn = true;
      addLog(LOG_LEVEL_DEBUG, F("INIT: nextWakeRadioOn = true"));
    } 
  // }

  WiFi.persistent(false); // Do not use SDK storage of SSID/WPA parameters

  if (!isDeepSleepEnabled()){
    WifiAPconfig();
  }

  //After booting, we want all the tasks to run without delaying more than neccesary.
  //Plugins that need an initial startup delay need to overwrite their initial timerSensor value in PLUGIN_INIT
  //They should also check if we returned from deep sleep so that they can skip the delay in that case.
  for (byte x = 0; x < TASKS_MAX; x++){
    if (Settings.TaskDeviceTimer[x] !=0) {
      timerSensor[x] = millis() + (x * Settings.MessageDelay);
    }
  }

  timer100ms = 0; // timer for periodic actions 10 x per/sec
  timer1s = 0; // timer for periodic actions once per/sec
  timerwd = 0; // timer for watchdog once per 30 sec

  PluginInit();
  CPluginInit();
  WifiDisconnect();

  if (!isDeepSleepEnabled()){
    WebServerInit();
  }

  if (TxData){
    // Inicia automaticamente a estação!
    WifiConnect(1);
  
    // setup UDP
    if (Settings.UDPPort != 0) portUDP.begin(Settings.UDPPort);

    // Setup MQTT Client
    byte ProtocolIndex = getProtocolIndex(Settings.Protocol[0]);
    if (Protocol[ProtocolIndex].usesMQTT && Settings.ControllerEnabled[0]) MQTTConnect();
    sendSysInfoUDP(3);
  }

  initTime();

  #if FEATURE_ADC_VCC
  vcc = ESP.getVcc() / 1000.0;
  #endif

  if (TxData && !isDeepSleepEnabled()){
  // Start DNS, only used if the ESP has no valid WiFi config
  // It will reply with it's own address on all DNS requests
  // (captive portal concept)
    if (wifiSetup) dnsServer.start(DNS_PORT, "*", apIP);
  }

  writeDefaultCSS();
  

}


/*********************************************************************************************\
 * MAIN LOOP
\*********************************************************************************************/
void loop()
{
  loopCounter++;

  // Deep sleep mode, just run all tasks one time and go back to sleep as fast as possible
  if (isDeepSleepEnabled())
  {
      run50TimesPerSecond();
      run10TimesPerSecond();
      runEach30Seconds();
      runOncePerSecond();
      
      if (TxData){
        // Aguarda Configuração via MQTT
        for (int i=0; i < 10; i++){
          if(Settings.ControllerEnabled[0]) MQTTclient.loop();
        }
      }
      deepSleep(Settings.Delay, NextWakeRadioOn);
      //deepsleep will never return, its a special kind of reboot
  }
  //normal mode, run each task when its time
  else
  {

    if (millis() > timer20ms)
      run50TimesPerSecond();

    if (millis() > timer100ms)
      run10TimesPerSecond();

    if (millis() > timerwd)
      runEach30Seconds();

    if (millis() > timer1s)
      runOncePerSecond();
  }

  loopCounterLast = loopCounter;
  loopCounter = 0;
  if (loopCounterLast > loopCounterMax)
    loopCounterMax = loopCounterLast;

  backgroundtasks();

}


/*********************************************************************************************\
 * Tasks that run 50 times per second
\*********************************************************************************************/

void run50TimesPerSecond()
{
  timer20ms = millis() + 20;
  // PluginCall(PLUGIN_FIFTY_PER_SECOND, 0, dummyString);

}

/*********************************************************************************************\
 * Tasks that run 10 times per second
\*********************************************************************************************/
void run10TimesPerSecond()
{
  start = micros();
  timer100ms = millis() + 100;
  PluginCall(PLUGIN_TEN_PER_SECOND, 0, dummyString);
  elapsed = micros() - start;
}


/*********************************************************************************************\
 * Tasks each second
\*********************************************************************************************/
void runOncePerSecond()
{
  dailyResetCounter++;
  if (dailyResetCounter > 86400) // 1 day elapsed... //86400
  {
    RTC.flashDayCounter=0;
    saveToRTC();
    dailyResetCounter=0;
    String log = F("SYS  : Reset 24h counters");
    addLog(LOG_LEVEL_INFO, log);
  }

  timer1s = millis() + 1000;

  checkSensors();

  if (Settings.ConnectionFailuresThreshold)
    if (connectionFailures > Settings.ConnectionFailuresThreshold)
      delayedReboot(60);

  if (cmd_within_mainloop != 0)
  {
    switch (cmd_within_mainloop)
    {
      case CMD_WIFI_DISCONNECT:
        {
          WifiDisconnect();
          break;
        }
      case CMD_REBOOT:
        {
          ESP.reset();
          break;
        }
    }
    cmd_within_mainloop = 0;
  }

  // clock events
  checkTime();

  unsigned long timer = micros();
  PluginCall(PLUGIN_ONCE_A_SECOND, 0, dummyString);

  checkSystemTimers();

  timer = micros() - timer;

  if (SecuritySettings.Password[0] != 0)
  {
    if (WebLoggedIn)
      WebLoggedInTimer++;
    if (WebLoggedInTimer > 300)
      WebLoggedIn = false;
  }

  // I2C Watchdog feed
  if (Settings.WDI2CAddress != 0)
  {
    Wire.beginTransmission(Settings.WDI2CAddress);
    Wire.write(0xA5);
    Wire.endTransmission();
  }

  if (Settings.SerialLogLevel == 5)
  {
    Serial.print(F("10 ps:"));
    Serial.print(elapsed);
    Serial.print(F(" uS  1 ps:"));
    Serial.println(timer);
  }

  if (timerAPoff != 0 && millis() > timerAPoff)
  {
    timerAPoff = 0;
    WifiAPMode(false);
  }

  // STATUS
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  // log = String(F("MQTT connection failures: "))+String(100*connectionFailures/connTotal)+String(F("%"));;
  // log += String(F("\nWifi connection failures: "))+String(100*wifiConnFail/wifiConnTotal)+String(F("%"));
  
  // TODO criar global
  ControllerSettingsStruct ControllerSettings;
  LoadControllerSettings(0, (byte*)&ControllerSettings, sizeof(ControllerSettings)); // todo index is now fixed to 0
  IPAddress MQTTBrokerIP(ControllerSettings.IP);
  bool ret = Ping.ping(MQTTBrokerIP,1);
  int serverPing = Ping.averageTime();
  String log = String(F("\nServer ping: "))+String(serverPing)+String(F("ms"));
  
  log += String(F("\nWifi scan: \n"))+String(wifiScan());
  // log += String(F("\nFree space: ")+String(freeSpace)+String(F(" bytes")));

  addLog(LOG_LEVEL_DEBUG, log);
}

/*********************************************************************************************\
 * Tasks each 30 seconds
\*********************************************************************************************/
void runEach30Seconds()
{
  wdcounter++;
  timerwd = millis() + 30000;
 
  if (!isDeepSleepEnabled()) if(Settings.ControllerEnabled[0]) MQTTCheck();

  //  if (Settings.UseSSDP) SSDP_update();

  #if FEATURE_ADC_VCC
  vcc = ESP.getVcc() / 1000.0;
  #endif

}


/*********************************************************************************************\
 * Check sensor timers
\*********************************************************************************************/
void checkSensors()
{
  String log;
  bool isDeepSleep = isDeepSleepEnabled();
  //check all the devices and only run the sendtask if its time, or we if we used deep sleep mode

  if (MQTTconnected){
    log = "TxData ->";
    TxData = true;
    logData = false;
    sendMqttLog();
  } else {
    if (RTC.syncCounter == 0){
      log = "logData ->";
      TxData = false;
      logData = true;
    } else {
      log = "Waiting for clock sync ->";
      TxData = false;
      logData = false;
    }
  }
  addLog(LOG_LEVEL_DEBUG, log);

  if (isDeepSleep){

    for (byte x = 0; x < TASKS_MAX; x++){
      if (Settings.TaskDeviceEnabled[x]){
        SensorSendTask(x);
      }
    }
  } else {
  
    for (byte x = 0; x < TASKS_MAX; x++)
    {
      if (
          (Settings.TaskDeviceTimer[x] != 0) &&
          (millis() > timerSensor[x]) &&
          (Settings.TaskDeviceEnabled[x])
      )
      {
        timerSensor[x] = millis() + Settings.TaskDeviceTimer[x] * 1000;
        if (timerSensor[x] == 0) // small fix if result is 0, else timer will be stopped...
          timerSensor[x] = 1;
        SensorSendTask(x);
      }
    }
  }


  RTC.readCounter++;

  saveUserVarToRTC();
}


/*********************************************************************************************\
 * send all sensordata
\*********************************************************************************************/
// void SensorSendAll()
// {
//   for (byte x = 0; x < TASKS_MAX; x++)
//   {
//     SensorSendTask(x);
//   }
// }


/*********************************************************************************************\
 * send specific sensor task data
\*********************************************************************************************/
void SensorSendTask(byte TaskIndex)
{
  if (Settings.TaskDeviceEnabled[TaskIndex])
  {
    byte varIndex = TaskIndex * VARS_PER_TASK;

    boolean success = false;
    byte DeviceIndex = getDeviceIndex(Settings.TaskDeviceNumber[TaskIndex]);
    LoadTaskSettings(TaskIndex);

    struct EventStruct TempEvent;
    TempEvent.TaskIndex = TaskIndex;
    TempEvent.BaseVarIndex = varIndex;
    // TempEvent.idx = Settings.TaskDeviceID[TaskIndex]; todo check
    TempEvent.sensorType = Device[DeviceIndex].VType;

    double preValue[VARS_PER_TASK]; // store values before change, in case we need it in the formula
    for (byte varNr = 0; varNr < VARS_PER_TASK; varNr++) preValue[varNr] = UserVar[varIndex + varNr];

    if(Settings.TaskDeviceDataFeed[TaskIndex] == 0)  // only read local connected sensorsfeeds
      success = PluginCall(PLUGIN_READ, &TempEvent, dummyString);
    else
      success = true;

    if (success)
    {
      for (byte varNr = 0; varNr < VARS_PER_TASK; varNr++)
      {
        if (ExtraTaskSettings.TaskDeviceFormula[varNr][0] != 0)
        {
          String spreValue = String(preValue[varNr]);
          String formula = ExtraTaskSettings.TaskDeviceFormula[varNr];
          double value = UserVar[varIndex + varNr];
          double result = 0;
          String svalue = String(value);
          formula.replace(F("%pvalue%"), spreValue);
          formula.replace(F("%value%"), svalue);
          byte error = Calculate(formula.c_str(), &result);
          if (error == 0)
            UserVar[varIndex + varNr] = result;
        }
      }
      sendData(&TempEvent);
    }
  }
}


/*********************************************************************************************\
 * set global system timer
\*********************************************************************************************/
boolean setSystemTimer(unsigned long timer, byte plugin, byte Par1, byte Par2, byte Par3)
{
  // plugin number and par1 form a unique key that can be used to restart a timer
  // first check if a timer is not already running for this request
  boolean reUse = false;
  for (byte x = 0; x < SYSTEM_TIMER_MAX; x++)
    if (systemTimers[x].timer != 0)
    {
      if ((systemTimers[x].plugin == plugin) && (systemTimers[x].Par1 == Par1))
      {
        systemTimers[x].timer = millis() + timer;
        reUse = true;
        break;
      }
    }

  if (!reUse)
  {
    // find a new free timer slot...
    for (byte x = 0; x < SYSTEM_TIMER_MAX; x++)
      if (systemTimers[x].timer == 0)
      {
        systemTimers[x].timer = millis() + timer;
        systemTimers[x].plugin = plugin;
        systemTimers[x].Par1 = Par1;
        systemTimers[x].Par2 = Par2;
        systemTimers[x].Par3 = Par3;
        break;
      }
  }
}


/*********************************************************************************************\
 * set global system command timer
\*********************************************************************************************/
boolean setSystemCMDTimer(unsigned long timer, String& action)
{
  for (byte x = 0; x < SYSTEM_CMD_TIMER_MAX; x++)
    if (systemCMDTimers[x].timer == 0)
    {
      systemCMDTimers[x].timer = millis() + timer;
      systemCMDTimers[x].action = action;
      break;
    }
}


/*********************************************************************************************\
 * check global system timers
\*********************************************************************************************/
boolean checkSystemTimers()
{
  for (byte x = 0; x < SYSTEM_TIMER_MAX; x++)
    if (systemTimers[x].timer != 0)
    {
      if (timeOut(systemTimers[x].timer))
      {
        struct EventStruct TempEvent;
        TempEvent.Par1 = systemTimers[x].Par1;
        TempEvent.Par2 = systemTimers[x].Par2;
        TempEvent.Par3 = systemTimers[x].Par3;
        for (byte y = 0; y < PLUGIN_MAX; y++)
          if (Plugin_id[y] == systemTimers[x].plugin)
            Plugin_ptr[y](PLUGIN_TIMER_IN, &TempEvent, dummyString);
        systemTimers[x].timer = 0;
      }
    }

  for (byte x = 0; x < SYSTEM_CMD_TIMER_MAX; x++)
    if (systemCMDTimers[x].timer != 0)
      if (timeOut(systemCMDTimers[x].timer))
      {
        struct EventStruct TempEvent;
        parseCommandString(&TempEvent, systemCMDTimers[x].action);
        if (!PluginCall(PLUGIN_WRITE, &TempEvent, systemCMDTimers[x].action))
          ExecuteCommand(VALUE_SOURCE_SYSTEM, systemCMDTimers[x].action.c_str());
        systemCMDTimers[x].timer = 0;
        systemCMDTimers[x].action = "";
      }
}


/*********************************************************************************************\
 * run background tasks
\*********************************************************************************************/
bool runningBackgroundTasks=false;
void backgroundtasks()
{
  tcpCleanup();
  //prevent recursion!
  if (runningBackgroundTasks)
  {
    yield();
    return;
  }
  runningBackgroundTasks=true;

  if (Settings.UseSerial)
    if (Serial.available())
      if (!PluginCall(PLUGIN_SERIAL_IN, 0, dummyString))
        serial();

  
  // process DNS, only used if the ESP has no valid WiFi config
  
  if (!isDeepSleepEnabled()){
    if (wifiSetup) dnsServer.processNextRequest();
    if (!WebServerInitialized) WebServerInit();
    WebServer.handleClient();
  }

  if (TxData){
    if(Settings.ControllerEnabled[0]) {MQTTclient.loop();}
  }    

  yield();

  runningBackgroundTasks=false;
}
