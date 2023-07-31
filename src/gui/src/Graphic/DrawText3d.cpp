/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawText3d
*/

#include "DrawText3d.hpp"

Zappy::DrawText3d::DrawText3d()
{
}

void Zappy::DrawText3d::DrawTextCodepoint3D(Font font, int codepoint, Vector3 position, float fontSize, bool backface, Color tint)
{
    int index = GetGlyphIndex(font, codepoint);
    float scale = fontSize/(float)font.baseSize;

    position.x += (float)(font.glyphs[index].offsetX - font.glyphPadding)/(float)font.baseSize * scale;
    position.z += (float)(font.glyphs[index].offsetY - font.glyphPadding)/(float)font.baseSize * scale;

    Rectangle srcRec = { font.recs[index].x - (float)font.glyphPadding, font.recs[index].y - (float)font.glyphPadding,
                         font.recs[index].width + 2.0f * font.glyphPadding, font.recs[index].height + 2.0f*font.glyphPadding };

    float width = (float)(font.recs[index].width + 2.0f * font.glyphPadding)/(float)font.baseSize * scale;
    float height = (float)(font.recs[index].height + 2.0f * font.glyphPadding)/(float)font.baseSize * scale;

    if (font.texture.id > 0)
    {
        const float x = 0.0f;
        const float y = 0.0f;
        const float z = 0.0f;

        const float tx = srcRec.x/font.texture.width;
        const float ty = srcRec.y/font.texture.height;
        const float tw = (srcRec.x+srcRec.width)/font.texture.width;
        const float th = (srcRec.y+srcRec.height)/font.texture.height;

        rlCheckRenderBatchLimit(4 + 4*backface);
        rlSetTexture(font.texture.id);

        rlPushMatrix();
            rlTranslatef(position.x, position.y, position.z);
            rlRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            rlBegin(RL_QUADS);
                rlColor4ub(tint.r, tint.g, tint.b, tint.a);


                rlNormal3f(0.0f, 1.0f, 0.0f);                                   
                rlTexCoord2f(tx, ty); rlVertex3f(x, y, z);              
                rlTexCoord2f(tx, th); rlVertex3f(x, y, z + height);     
                rlTexCoord2f(tw, th); rlVertex3f(x + width, y, z + height);     
                rlTexCoord2f(tw, ty); rlVertex3f(x + width, y, z);              

                if (backface)
                {
                    rlNormal3f(0.0f, -1.0f, 0.0f);
                    rlTexCoord2f(tx, ty); rlVertex3f(x, y, z);          
                    rlTexCoord2f(tw, ty); rlVertex3f(x + width, y, z);          
                    rlTexCoord2f(tw, th); rlVertex3f(x + width, y, z + height); 
                    rlTexCoord2f(tx, th); rlVertex3f(x, y, z + height); 
                }
            rlEnd();
        rlPopMatrix();

        rlSetTexture(0);
    }
}

void Zappy::DrawText3d::DrawText3D(Font font, const char *text, Vector3 position, Color tint, float size)
{
    int length = TextLength(text);
    float textOffsetY = 0.0f;
    float textOffsetX = 0.0f;
    bool backface = true;
    float fontSpacing = true;
    float lineSpacing = true;
    float fontSize = 2 + size;
    float scale = fontSize / (float)font.baseSize;

    for (int i = 0; i < length;)
    {
        int codepointByteCount = 0;
        int codepoint = GetCodepoint(&text[i], &codepointByteCount);
        int index = GetGlyphIndex(font, codepoint);

        if (codepoint == 0x3f) codepointByteCount = 1;

        if (codepoint == '\n')
        {
            textOffsetY += scale + lineSpacing/(float)font.baseSize*scale;
            textOffsetX = 0.0f;
        }
        else
        {
            if ((codepoint != ' ') && (codepoint != '\t'))
            {
                DrawTextCodepoint3D(font, codepoint, (Vector3){ position.x + textOffsetX, position.y, position.z + textOffsetY }, fontSize, backface, tint);
            }

            if (font.glyphs[index].advanceX == 0) textOffsetX += (float)(font.recs[index].width + fontSpacing)/(float)font.baseSize*scale;
            else textOffsetX += (float)(font.glyphs[index].advanceX + fontSpacing)/(float)font.baseSize*scale;
        }

        i += codepointByteCount;
    }
}

Zappy::DrawText3d::~DrawText3d()
{
}