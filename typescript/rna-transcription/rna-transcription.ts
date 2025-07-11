export function toRna(rna: string): string {

  for (let i = 0 ; i < rna.length;i++) {
    if (rna[i] === 'T') {
      rna = rna.slice(0, i) + 'A' + rna.slice(i + 1);
    }else if (rna[i] === 'A') {
      rna = rna.slice(0, i) + 'U' + rna.slice(i + 1);
    }else if (rna[i] === 'C') {
      rna = rna.slice(0, i) + 'G' + rna.slice(i + 1);
    }else if (rna[i] === 'G') {
      rna = rna.slice(0, i) + 'C' + rna.slice(i + 1);
    }else {
      throw new Error('Invalid input DNA.');
    }
  }
  return rna;
  
}
