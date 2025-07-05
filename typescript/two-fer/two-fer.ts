export function twoFer(str:string): string {
  if (str === '') {
    return 'One for you, one for me.'
  }
  return 'One for ' + str + ', one for me.'
}
