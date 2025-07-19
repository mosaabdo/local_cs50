def main():
    # نأخذ الرقم من المستخدم كـ string لأن الأرقام الكبيرة ممكن تسبب مشاكل لو تعاملنا معها كأرقام مباشرة
    number = input("Number: ")

    # نتحقق من صحة الرقم باستخدام خوارزمية Luhn
    if check_luhn(number):
        # بناءً على الرقم نحدد نوع البطاقة
        if is_amex(number):
            print("AMEX")
        elif is_mastercard(number):
            print("MASTERCARD")
        elif is_visa(number):
            print("VISA")
        else:
            print("INVALID")
    else:
        # لو الرقم غير صحيح حسب خوارزمية Luhn
        print("INVALID")


def check_luhn(number):
    """تطبق خوارزمية Luhn للتحقق من صحة الرقم"""
    total = 0
    # نقلب الرقم علشان نبدأ العد من اليمين
    reversed_digits = number[::-1]

    for i, digit in enumerate(reversed_digits):
        n = int(digit)  # نحول كل رقم إلى عدد صحيح
        if i % 2 == 1:
            # كل رقم في الموضع الزوجي من اليمين (بسبب الصفرية يبدأ i من 0)
            n *= 2
            if n > 9:
                # لو الناتج رقمين، نجمع أرقامه، أو ببساطة نطرح 9 (مثلاً 12 → 1+2 = 3 أو 12-9 = 3)
                n -= 9
        total += n  # نجمع الناتج في المجموع الكلي

    # الرقم صالح إذا كان المجموع يقبل القسمة على 10
    return total % 10 == 0


def is_amex(number):
    """يتحقق إذا كانت البطاقة AMEX"""
    return len(number) == 15 and (number.startswith("34") or number.startswith("37"))


def is_mastercard(number):
    """يتحقق إذا كانت البطاقة Mastercard"""
    return len(number) == 16 and number[:2] in ["51", "52", "53", "54", "55"]


def is_visa(number):
    """يتحقق إذا كانت البطاقة Visa"""
    return len(number) in [13, 16] and number.startswith("4")


# استدعاء الدالة الرئيسية
main()
