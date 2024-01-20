#include "TextList.h"
#include "Utils.h"
#include <iostream>


TextList::TextList(Vector2f pos, Vector2f offset) : m_position(pos), m_offset(offset) {}

void TextList::updateAll() {
    for (size_t i=0; i<m_entries.size(); i++) {
        auto pos = i<1?m_position:m_entries[i-1].getGlobalBounds().getPosition()+m_offset;
        m_entries[i].setPosition(pos);
        m_entries[i].setFont(m_font);
        m_entries[i].setCharacterSize(m_fontSize);
        m_entries[i].setOutlineThickness(m_outlineThickness);
        m_entries[i].setFillColor(m_fillColor);
        m_entries[i].setFillColor({255,255,0});
        m_entries[i].setOutlineColor(m_outlineColor);

        // white for the selected one
        m_entries[m_selected].setFillColor({255,255,255});
    }
}

void TextList::AddEntry(std::string title) {
    Text m_text;
    m_text.setString(title);
    m_entries.push_back(m_text);
}

std::vector<Text> TextList::getEntries() const {
    return m_entries;
}

void TextList::setFont(Font &f) {
    m_font = f;
}

void TextList::setFontSize(int s) {
    m_fontSize = s;
}

void TextList::setFillColor(Color &c) {
    m_fillColor = c;
}

void TextList::setOutlineColor(Color &c) {
    m_outlineColor = c;
}

void TextList::setOutlineThickness(int t) {
    m_outlineThickness = t;
}

int TextList::getSelected() {
    return m_selected;
}

void TextList::moveCursorDown() {
    m_selected++;
    if (m_selected>m_entries.size()-1)
        m_selected = 0;
}

void TextList::moveCursorUp() {
    m_selected--;
    if (m_selected<0)
        m_selected = m_entries.size()-1;
}