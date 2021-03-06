#include "Hardware/Peripherals.h"
#include "DBG.h"
#include "Hardware/Button/MCPButton.h"
#include "Hardware/Button/MCPInterruptButton.h"
#include "Hardware/Button/TeensyButton.h"
#include "Hardware/Led/MCPLed.h"
#include "Hardware/Led/PCALed.h"
#include "Hardware/Led/TeensyLed.h"
#include "Hardware/Pins.h"
#include "Hardware/Slider/TeensySlider.h"

void mcpInterruptCallback()
{
  //mcpThis->readGPIOAB();
  //uint8_t pin = mcpThis->getLastInterruptPin();
  //DBG("Interrupt from MCP pin %d\n", pin);
  //attachInterrupt(20, mcpInterruptCallback, FALLING);
}

constexpr unsigned long DebounceTime = 10; // 10 ms debounce

Peripherals::Peripherals()
  : sld(PIN_SLD_DIN, PIN_SLD_CLK, PIN_SLD_CS), mcp1(), mcp2()
  , pca1(0x0, PCA9685_MODE_LED_DIRECT, 800.0)
  , pca2(0x1, PCA9685_MODE_LED_DIRECT, 800.0)
  , pca3(0x2, PCA9685_MODE_LED_DIRECT, 800.0)
  , presetMemory(0b1010'010, 128 / 8 * 1024)
  // Buttons
  , stepButtons{
    MCPButton(mcp1, PIN_PB_1, DebounceTime),
    MCPButton(mcp1, PIN_PB_2, DebounceTime),
    MCPButton(mcp1, PIN_PB_3, DebounceTime),
    MCPButton(mcp1, PIN_PB_4, DebounceTime),
    MCPButton(mcp1, PIN_PB_5, DebounceTime),
    MCPButton(mcp1, PIN_PB_6, DebounceTime),
    MCPButton(mcp1, PIN_PB_7, DebounceTime),
    MCPButton(mcp1, PIN_PB_8, DebounceTime),
    MCPButton(mcp1, PIN_PB_9, DebounceTime),
    MCPButton(mcp1, PIN_PB_10, DebounceTime),
    MCPButton(mcp1, PIN_PB_11, DebounceTime),
    MCPButton(mcp1, PIN_PB_12, DebounceTime),
    MCPButton(mcp1, PIN_PB_13, DebounceTime),
    MCPButton(mcp1, PIN_PB_14, DebounceTime),
    MCPButton(mcp1, PIN_PB_15, DebounceTime),
    MCPButton(mcp1, PIN_PB_16, DebounceTime)}
  , instrumentButtons{
    MCPButton(mcp2, PIN_PB_INST_1, DebounceTime),
    MCPButton(mcp2, PIN_PB_INST_2, DebounceTime),
    MCPButton(mcp2, PIN_PB_INST_3, DebounceTime),
    MCPButton(mcp2, PIN_PB_INST_4, DebounceTime)}
  , yellowButton(mcp2, PIN_PB_YELLOW, DebounceTime)
  , redButton(mcp2, PIN_PB_RED, DebounceTime)
  , blueButton(mcp2, PIN_PB_BLUE, DebounceTime)
  , greenButton(mcp2, PIN_PB_GREEN, DebounceTime)
  , saveButton(mcp3, PIN_PB_SAVE, DebounceTime)
  , loadButton(mcp3, PIN_PB_LOAD, DebounceTime)
  // Leds
  , redLeds{
    PCALed(pca1, PCA9685_LED0, true),
    PCALed(pca1, PCA9685_LED1, true),
    PCALed(pca1, PCA9685_LED2, true),
    PCALed(pca1, PCA9685_LED3, true),
    PCALed(pca1, PCA9685_LED4, true),
    PCALed(pca1, PCA9685_LED5, true),
    PCALed(pca1, PCA9685_LED6, true),
    PCALed(pca1, PCA9685_LED7, true),
    PCALed(pca1, PCA9685_LED8, true),
    PCALed(pca1, PCA9685_LED9, true),
    PCALed(pca1, PCA9685_LED10,true),
    PCALed(pca1, PCA9685_LED11,true),
    PCALed(pca1, PCA9685_LED12,true),
    PCALed(pca1, PCA9685_LED13,true),
    PCALed(pca1, PCA9685_LED14,true),
    PCALed(pca1, PCA9685_LED15,true)}
  , blueLeds{
    PCALed(pca2, PCA9685_LED0, true),
    PCALed(pca2, PCA9685_LED1, true),
    PCALed(pca2, PCA9685_LED2, true),
    PCALed(pca2, PCA9685_LED3, true),
    PCALed(pca2, PCA9685_LED4, true),
    PCALed(pca2, PCA9685_LED5, true),
    PCALed(pca2, PCA9685_LED6, true),
    PCALed(pca2, PCA9685_LED7, true),
    PCALed(pca2, PCA9685_LED8, true),
    PCALed(pca2, PCA9685_LED9, true),
    PCALed(pca2, PCA9685_LED10,true),
    PCALed(pca2, PCA9685_LED11,true),
    PCALed(pca2, PCA9685_LED12,true),
    PCALed(pca2, PCA9685_LED13,true),
    PCALed(pca2, PCA9685_LED14,true),
    PCALed(pca2, PCA9685_LED15,true)}
  , greenLeds{
    PCALed(pca3, PCA9685_LED0, true),
    PCALed(pca3, PCA9685_LED1, true),
    PCALed(pca3, PCA9685_LED2, true),
    PCALed(pca3, PCA9685_LED3, true),
    PCALed(pca3, PCA9685_LED4, true),
    PCALed(pca3, PCA9685_LED5, true),
    PCALed(pca3, PCA9685_LED6, true),
    PCALed(pca3, PCA9685_LED7, true),
    PCALed(pca3, PCA9685_LED8, true),
    PCALed(pca3, PCA9685_LED9, true),
    PCALed(pca3, PCA9685_LED10,true),
    PCALed(pca3, PCA9685_LED11,true),
    PCALed(pca3, PCA9685_LED12,true),
    PCALed(pca3, PCA9685_LED13,true),
    PCALed(pca3, PCA9685_LED14,true),
    PCALed(pca3, PCA9685_LED15,true)}
  , instrumentLeds{
    MCPLed(mcp2, PIN_LED_INST_1),
    MCPLed(mcp2, PIN_LED_INST_2),
    MCPLed(mcp2, PIN_LED_INST_3),
    MCPLed(mcp2, PIN_LED_INST_4)}
  , yellowLed(mcp2, PIN_LED_YELLOW)
  , redLed(mcp2, PIN_LED_RED)
  , blueLed(mcp2, PIN_LED_BLUE)
  , greenLed(mcp2, PIN_LED_GREEN)
  // Sliders
  , instrumentSliders{
    std::array<MCPSlider, s_numSliderRows>{
      MCPSlider(adc, PIN_ADC_INST_1_TOP),
      MCPSlider(adc, PIN_ADC_INST_1_BOT)},
    std::array<MCPSlider, s_numSliderRows>{
      MCPSlider(adc, PIN_ADC_INST_2_TOP),
      MCPSlider(adc, PIN_ADC_INST_2_BOT)},
    std::array<MCPSlider, s_numSliderRows>{
      MCPSlider(adc, PIN_ADC_INST_3_TOP),
      MCPSlider(adc, PIN_ADC_INST_3_BOT)},
    std::array<MCPSlider, s_numSliderRows>{
      MCPSlider(adc, PIN_ADC_INST_4_TOP),
      MCPSlider(adc, PIN_ADC_INST_4_BOT)}}
  , redSlider1(PIN_POT_RED_1)
  , redSlider2(PIN_POT_RED_2)
  , blackSlider1(PIN_POT_BLACK_1)
  , blackSlider2(PIN_POT_BLACK_2)
{
  DBG("Size of MCP23017: %d\n", sizeof(Adafruit_MCP23017));
  DBG("Size of PCA: %d\n", sizeof(PCA9685));
  DBG("Size of SLD: %d\n", sizeof(LedControl));
  DBG("Size of MCP3008: %d\n", sizeof(Adafruit_MCP3008));

  DBG("Size of TeensyLed: %d\n", sizeof(TeensyLed));
  DBG("Size of MCPLed: %d\n", sizeof(MCPLed));
  DBG("Size of PCALed: %d\n", sizeof(PCALed));
  DBG("Size of TeensyButton: %d\n", sizeof(TeensyButton));
  DBG("Size of MCPButton: %d\n", sizeof(MCPButton));
  DBG("Size of MCPInterruptButton: %d\n", sizeof(MCPInterruptButton));
  DBG("Size of TeensySlider: %d\n", sizeof(TeensySlider));
  DBG("Size of MCPSlider: %d\n", sizeof(MCPSlider));

  //mcpThis = &mcp1;
}

void Peripherals::init(unsigned long startupDelay)
{
  delay(startupDelay);

  sld.shutdown(0, false);
  sld.setIntensity(0, 12); // sets brightness (0~15 possible values)
  sld.clearDisplay(0);
  sld.setScanLimit(0, 7);

  delay(startupDelay);

  pca1.setup();
  pca2.setup();
  pca3.setup();

  mcp1.begin(0);
  mcp2.begin(1);
  mcp3.begin(2);
  adc.begin(PIN_ADC_CLK, PIN_ADC_DIN, PIN_ADC_DOUT, PIN_ADC_CS);

  presetMemory.begin();
  DBG("EEPROM size: %d Kbits\n", presetMemory.determineSize() * 8);

  // mcp1.setupInterrupts(true, false, LOW);
  // pinMode(20, INPUT);
  // attachInterrupt(20, mcpInterruptCallback, FALLING);

  for (auto& led : redLeds)
    led.init();

  for (auto& led : greenLeds)
    led.init();

  for (auto& led : blueLeds)
    led.init();

  for (auto& led : instrumentLeds)
    led.init();

  yellowLed.init();
  redLed.init();
  blueLed.init();
  greenLed.init();

  for (auto& button : stepButtons)
    button.init();

  for (auto& button : instrumentButtons)
    button.init();

  yellowButton.init();
  redButton.init();
  blueButton.init();
  greenButton.init();
  saveButton.init();
  loadButton.init();

  redSlider1.init();
  redSlider2.init();
  blackSlider1.init();
  blackSlider2.init();
  for (auto& sliderRow : instrumentSliders)
    for (auto& slider : sliderRow)
      slider.init();
}

void Peripherals::updateButtons()
{
  for (auto& button : stepButtons)
    button.update();

  for (auto& button : instrumentButtons)
    button.update();

  yellowButton.update();
  redButton.update();
  blueButton.update();
  greenButton.update();
  saveButton.update();
  loadButton.update();
}

void Peripherals::clearLeds()
{
  for (auto& led : redLeds)
    led.turnOff();

  for (auto& led : greenLeds)
    led.turnOff();

  for (auto& led : blueLeds)
    led.turnOff();

  for (auto& led : instrumentLeds)
    led.turnOff();

  yellowLed.turnOff();
  redLed.turnOff();
  blueLed.turnOff();
  greenLed.turnOff();
}

void Peripherals::updateLeds()
{
  for (auto& led : redLeds)
    led.update();

  for (auto& led : greenLeds)
    led.update();

  for (auto& led : blueLeds)
    led.update();

  for (auto& led : instrumentLeds)
    led.update();

  yellowLed.update();
  redLed.update();
  blueLed.update();
  greenLed.update();
}