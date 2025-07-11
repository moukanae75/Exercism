export const COLORS = [
  'black',    // 0
  'brown',    // 1
  'red',      // 2
  'orange',   // 3
  'yellow',   // 4
  'green',    // 5
  'blue',     // 6
  'violet',   // 7
  'grey',     // 8
  'white',    // 9
];

export function decodedResistorValue(colors: string[]): string {
  const first = COLORS.indexOf(colors[0]);
  const second = COLORS.indexOf(colors[1]);
  const third = COLORS.indexOf(colors[2]);
  
  const baseValue = first * 10 + second;
  
  const finalValue = baseValue * Math.pow(10, third);
  
  return formatValue(finalValue);
}

function formatValue(value: number): string {
  if (value >= 1_000_000_000) {
    const gigaValue = value / 1_000_000_000;
    return `${gigaValue} gigaohms`;
  }
  
  if (value >= 1_000_000) {
    const megaValue = value / 1_000_000;
    return `${megaValue} megaohms`;
  }
  
  if (value >= 1_000) {
    const kiloValue = value / 1_000;
    return `${kiloValue} kiloohms`;
  }
  
  return `${value} ohms`;
}


