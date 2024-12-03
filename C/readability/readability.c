#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float calculate_index(int letters, int words, int sentences);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float index = calculate_index(letters, words, sentences);
    int grade = index;
    if (index < 2)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 2 && index <= 16.5)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// Coleman-Liau index readability test
float calculate_index(int letters, int words, int sentences)
{
    float words_f = words;
    float index = 0.0588 * (letters / words_f * 100) - 0.296 * (sentences / words_f * 100) - 15.8;
    index = roundf(index);

    return index;
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, ascii = 0; i <= strlen(text); i++)
    {
        ascii = toupper(text[i]);
        if ((ascii >= 65) && (ascii <= 90))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (((text[i] == ' ') && (text[i - 1] != ' ') && (text[i - 1] != '\0')) ||
            ((text[i] == '\0') && (text[i - 1] != ' ') && (text[i - 1] != '\0')))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if ((((text[i] == '.') && (text[i - 1] != '.')) && !((text[i + 2] >= 97) && (text[i + 2] <= 122))) ||
            ((text[i] == '!') && (text[i - 1] != '!') && (text[i - 1] != '?')) ||
            ((text[i] == '?') && (text[i - 1] != '?') && (text[i - 1] != '!')))
        {
            sentences++;
        }
    }
    return sentences;
}
