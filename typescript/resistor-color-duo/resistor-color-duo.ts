export const COLORS = [
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
export function decodedValue(colors: string[]):number {
  if(COLORS.indexOf(colors[1]) === 0) {
    return COLORS.indexOf(colors[0])*10;}
  return COLORS.indexOf(colors[0])*10+COLORS.indexOf(colors[1]);
}



