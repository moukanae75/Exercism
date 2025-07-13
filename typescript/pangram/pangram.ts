export function isPangram(text: string): boolean {
  const alphabet = 'abcdefghijklmnopqrstuvwxyz';
  const lowerText = text.toLowerCase();
  
  for (const char of alphabet) {
    console.log(`Checking for character: ${char}`);
    if (!lowerText.includes(char)) {
      return false;
    }
  }
  
  return true;
  
}
