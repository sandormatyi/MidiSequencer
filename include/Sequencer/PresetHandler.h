#pragma once

#include <inttypes.h>
#include <array>
#include "Instrument.h"
#include "Sequencer.h"

class I2C_eeprom;

class PresetHandler
{
private:
    static constexpr uint8_t s_bankNumber = Sequencer::s_instrumentNumber;
    static constexpr uint8_t s_presetPerBank = Instrument::s_stepNumber;
    static constexpr uint16_t s_presetSize = Instrument::s_patternSizeInBytes;
    static constexpr uint16_t s_firstPresetAddress = 0x1000;

public:
    static void savePresetToBank(I2C_eeprom& ee, uint8_t bankIdx, uint8_t presetIdx, const std::array<uint8_t, s_presetSize>& data);
    static std::array<uint8_t, s_presetSize> loadPresetFromBank(I2C_eeprom& ee, uint8_t bankIdx, uint8_t presetIdx);
};