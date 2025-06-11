#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // التأكد من أن المستخدم أدخل اسم ملف واحد فقط
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // فتح ملف الصورة الذي سيتم استعادته
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[512];          // مصفوفة لقراءة كتلة بحجم 512 بايت
    FILE *img = NULL;          // مؤشر ملف جديد للصور المستعادة
    int file_count = 0;        // عداد أسماء الملفات (000.jpg، 001.jpg، ...)
    bool found_jpeg = false;   // علم للتأكد من أننا بدأنا في كتابة JPEG

    while (fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        // تحقق من بداية كتلة JPEG (التوقيع)
        bool is_jpeg_start = 
            buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0;

        if (is_jpeg_start)
        {
            // إذا كنا نكتب صورة سابقة، نغلقها أولًا
            if (found_jpeg)
            {
                fclose(img);
            }
            else
            {
                found_jpeg = true; // وجدنا أول صورة
            }

            // تهيئة اسم الملف الجديد مثل "000.jpg"
            char filename[8];
            sprintf(filename, "%03i.jpg", file_count);
            file_count++;

            // فتح ملف جديد للكتابة
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create %s\n", filename);
                fclose(file);
                return 1;
            }

            // كتابة الكتلة الحالية (بداية صورة جديدة)
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
        else if (found_jpeg)
        {
            // إذا كنا في وضع كتابة صورة، نكتب الكتلة الحالية في الملف المفتوح
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
        // إذا لم نجد توقيع JPEG ولم نبدأ في كتابة صورة، نتجاهل الكتلة
    }

    // إغلاق الملفات المفتوحة
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(file);

    return 0;
}
