def main():
    # نأخذ النص من المستخدم
    text = input("Text: ")

    # نحسب عدد الحروف والكلمات والجمل
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # نحسب متوسط الحروف والجمل لكل 100 كلمة
    L = (letters / words) * 100
    S = (sentences / words) * 100

    # نحسب مؤشر Coleman-Liau
    index = 0.0588 * L - 0.296 * S - 15.8
    grade = round(index)  # نقرب الناتج لأقرب عدد صحيح

    # نطبع النتيجة حسب المطلوب
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def count_letters(text):
    """تحسب عدد الحروف في النص"""
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count


def count_words(text):
    """تحسب عدد الكلمات في النص"""
    count = 1  # نبدأ بـ 1 لأن أول كلمة غالباً لا يسبقها مسافة
    for char in text:
        if char == ' ':
            count += 1
    return count


def count_sentences(text):
    """تحسب عدد الجمل في النص"""
    count = 0
    for char in text:
        if char in ['.', '!', '?']:
            count += 1
    return count


# استدعاء الدالة الرئيسية
main()
