
#include <iostream>
#include <vector>

struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct coordinate
{
    int x;
    int y;
};

class Filter
{
public:
    std::vector<std::vector<RGB>> convertTo2D(unsigned char *imageData, int width, int height)
    {
        std::vector<std::vector<RGB>> output;
        int length = width * height * 3;
        RGB color;

        for (int i = 0; i < height; ++i)
        {
            std::vector<RGB> row;
            for (int j = 0; j < width * 3; j += 3)
            {
                color.r = imageData[i * width * 3 + j + 0];
                color.g = imageData[i * width * 3 + j + 1];
                color.b = imageData[i * width * 3 + j + 2];
                row.emplace_back(color);
            }
            output.emplace_back(row);
        }

        return output;
    }
    const std::vector<std::vector<RGB>> createCanvas(int width, int height)
    {
        std::vector<std::vector<RGB>> canvas(height, std::vector<RGB>(width, {0, 0, 0}));
        return canvas;
    }

    void placeTileOnCanvas(std::vector<std::vector<RGB>> &canvas,
                           const std::vector<std::vector<RGB>> &tileImage,
                           int xPos, int yPos, int tileWidth, int tileHeight)
    {
        for (int i = 0; i < tileHeight; ++i)
        {
            for (int j = 0; j < tileWidth; ++j)
            {
                int canvasY = yPos + i;
                int canvasX = xPos + j;

                if (canvasY < canvas.size() && canvasX < canvas[0].size())
                {
                    canvas[canvasY][canvasX] = tileImage[i][j];
                }
            }
        }
    }

    void saveToPNG(const std::vector<std::vector<RGB>> &imageData, int width, int height, const char *filename)
    {
        std::vector<unsigned char> imageFlat;
        imageFlat.reserve(width * height * 3);

        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                const RGB &color = imageData[i][j];
                imageFlat.push_back(color.r);
                imageFlat.push_back(color.g);
                imageFlat.push_back(color.b);
            }
        }

        if (stbi_write_png(filename, width, height, 3, imageFlat.data(), width * 3))
        {
            std::cout << "Image saved successfully to " << filename << std::endl;
        }
        else
        {
            std::cout << "Failed to save image!" << std::endl;
        }
    }
};