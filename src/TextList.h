#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class TextList {
public:
    TextList();
    TextList(Vector2f pos, Vector2f offset);
    void updateAll();
    void AddEntry(std::string title);
    std::vector<Text> getEntries() const;
    void setFont(Font &f);
    void setFontSize(int s);
    void setFillColor(Color &c);
    void setOutlineColor(Color &c);
    void setOutlineThickness(int t);
    void moveCursorDown();
    void moveCursorUp();
    int getSelected();
private:
    std::vector<Text> m_entries;
    Vector2f m_position, m_offset;
    Font m_font;
    Color m_fillColor, m_outlineColor;
    int m_outlineThickness = 0;
    int m_fontSize = 30;
    int m_selected = 0;
};