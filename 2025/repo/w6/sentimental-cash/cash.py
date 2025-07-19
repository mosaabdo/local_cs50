def main():
    # اطلب المبلغ من المستخدم وتأكد إنه موجب
    while True:
        try:
            change = float(input("Change: "))
            if change >= 0:
                break
        except ValueError:
            # لو المستخدم دخل قيمة غير رقمية
            continue
    
    # حوّل المبلغ إلى سنتات وتخلص من الكسور العشرية
    cents = round(change * 100)

    # حساب أقل عدد من العملات
    coins = calculate_coins(cents)

    # طباعة النتيجة
    print(coins)


def calculate_coins(cents):
    counter = 0
    for coin in [25, 10, 5, 1]:
        counter += cents // coin
        cents %= coin
    return counter


# استدعاء الدالة الرئيسية
main()
