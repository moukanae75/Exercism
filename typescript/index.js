// نسخ الكود من TypeScript مباشرة
const COLORS = [
  'black',
  'brown',
  'red',
  'orange',
  'yellow',
  'green',
  'blue',
  'violet',
  'grey',
  'white',
];

const colorCode = (color) => {
  return COLORS.indexOf(color);
};

// تصحيح منطق الحساب
function decodedValue(first, second, third) {
  // للمقاومة: الأول * 10 + الثاني = القيمة، الثالث = التسامح
  return `${colorCode(first)}${colorCode(second)}`;
}

// جعل الدوال متاحة عالمياً للاستخدام في HTML
window.colorCode = colorCode;
window.decodedValue = decodedValue;
window.COLORS = COLORS;