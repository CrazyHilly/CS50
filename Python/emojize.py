import emoji

text = input("Input: ").strip().lower()
print("Output:", emoji.emojize(text, language='alias'))