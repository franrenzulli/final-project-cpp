#include "TextList.h"
#include "Utils.h"

TextList::TextList(Vector2f pos, Vector2f offset) : m_position(pos), m_offset(offset) {}

void TextList::updateAll() {
    for (size_t i=0; i<m_entries.size(); i++) {
        auto pos = i<1?m_position:m_entries[i-1].getGlobalBounds().getPosition()+m_offset;
        // m_entries[i].setOrigin(Center(m_entries[i]));
        m_entries[i].setPosition(pos);
        m_entries[i].setFont(m_font);
        m_entries[i].setCharacterSize(m_fontSize);
        m_entries[i].setFillColor(m_fillColor);
        m_entries[i].setOutlineColor(m_outlineColor);
        m_entries[i].setOutlineThickness(m_outlineThickness);
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