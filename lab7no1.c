#include <stdio.h>

double functionM(void);
int functionN(int n, double x);
double functionO(double, int, double, int);
double functionP(int a, int n, int b, int c);

int main(void) {
    int a, b, c, d, e;
    double r, s, t, u, v;

    functionM(); // ผ่าน: เรียกใช้ได้ปกติ
    a = functionM(); // ผ่าน: เป็นการ Implicit cast จาก double ไป int (ค่าทศนิยมจะถูกตัดทิ้ง)
    
    b = functionN(a, b); // ผ่าน (มี Warning): b เป็น int แต่ฟังก์ชันรับ double คอมไพเลอร์จะแปลง int เป็น double ให้

    r = functionO(r, a, s, b); // ผ่าน: a และ b ที่เป็น int จะถูกโปรโมตเป็น double ตามที่ฟังก์ชันต้องการ

    s = functionP(a, b, c, d, e); // ไม่ผ่าน (Error): ส่ง argument 5 ตัว แต่ Prototype กำหนดไว้แค่ 4 ตัว (Too many arguments)

    u = functionM(); // ผ่าน
    
    c = d + functionN(r, s); // ผ่าน (มี Warning): r เป็น double แต่ฟังก์ชันรับ int (ข้อมูลทศนิยมของ r จะหายไปก่อนเข้าฟังก์ชัน)

    t = s * functionO(r, a, r, a); // ผ่าน: รูปแบบถูกต้องตาม Prototype

    a = v + functionP(r, s, t, t); // ผ่าน (มี Warning): r, s, t เป็น double แต่ฟังก์ชันรับ int (ข้อมูลทศนิยมจะถูกตัดออกทั้งหมด)

    functionP(functionN(a, a), s, t, t+r); // ผ่าน (มี Warning): s, t, t+r เป็น double แต่ฟังก์ชันรับ int (ข้อมูลทศนิยมจะถูกตัดออก)

    v = functionP(functionN(a, a), s, t, t+r); // ผ่าน (มี Warning): เหมือนบรรทัดก่อนหน้า

    return 0;
}