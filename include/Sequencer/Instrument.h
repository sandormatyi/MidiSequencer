#pragma once

#include <inttypes.h>
#include <array>
#include "Sequencer/Note.h"

class Instrument
{
public:
    static constexpr uint8_t s_stepNumber = 16;

    Instrument(const char *name, Note defaultNote);

    const char* getName() const;
    const Note &getDefaultNote() const;
    void setDefaultNote(Note defaultNote);

    bool isActiveNote(uint8_t idx) const;

    const Note& getNote(uint8_t idx) const;
    void setNote(uint8_t idx, Note note);
    void toggleNote(uint8_t idx);

    void clear();

private:
    char _name[7];
    Note _defaultNote;
    std::array<Note, s_stepNumber> _notes;
    std::array<bool, s_stepNumber> _activeNotes;
};