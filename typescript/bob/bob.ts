export function hey(message: unknown): unknown {
  if (typeof message !== 'string') {
    throw new Error('Input must be a string');
  }
  const lastmessage = message.trim();
  if (lastmessage === '') {
    return 'Fine. Be that way!'
  }

  const isQuestion = lastmessage.endsWith('?');

  const hasLetters = /[a-zA-Z]/.test(lastmessage);

  const Upper = lastmessage.toUpperCase()

  const isUpper = hasLetters&&Upper === lastmessage;

  if (isQuestion && isUpper) {
    return "Calm down, I know what I'm doing!"
  }else if (isQuestion) {
    return "Sure."
  }else if (isUpper) {
    return "Whoa, chill out!"
  }else {
    return "Whatever."
  }
  
  
}
