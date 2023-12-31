#include <iostream>
#include <string>
#include <gumbo.h>

void extractTextFromH1(GumboNode* node) {
    if (!node || node->type != GUMBO_NODE_ELEMENT) {
        return;
    }

    if (node->v.element.tag == GUMBO_TAG_H1) {
        if (node->v.element.children.length > 0) {
            GumboNode* textNode = static_cast<GumboNode*>(node->v.element.children.data[0]);
            if (textNode && textNode->type == GUMBO_NODE_TEXT) {
                std::cout << textNode->v.text.text << std::endl;
            }
        }
    }

    if (node->v.element.children.data) {
        GumboVector children = node->v.element.children;
        for (unsigned int i = 0; i < children.length; ++i) {
            extractTextFromH1(static_cast<GumboNode*>(children.data[i]));
        }
    }
}

int main() {
    const char* html = R"(
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Hello HTML</title>
        </head>
        <body>
            <h1>Hello, World!</h1>
        </body>
        </html>
    )";

    GumboOutput* output = gumbo_parse(html);

    if (output && output->root) {
        extractTextFromH1(output->root);
    } else {
        std::cerr << "Error parsing HTML" << std::endl;
    }
    gumbo_destroy_output(&kGumboDefaultOptions, output);

    return 0;
}
