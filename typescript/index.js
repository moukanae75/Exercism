class DnDCharacter {
  constructor () {
    console.log("cracter created succefuly")
    this.strength = DnDCharacter.generateAbilityScore();
    this.dexterity = DnDCharacter.generateAbilityScore();
    this.constitution = DnDCharacter.generateAbilityScore();

    this.intelligence = DnDCharacter.generateAbilityScore();
    this.wisdom = DnDCharacter.generateAbilityScore();
    this.charisma = DnDCharacter.generateAbilityScore();

      console.log("✅ تم إنشاء الشخصية بالقدرات:", {
            strength: this.strength,
            dexterity: this.dexterity,
            constitution: this.constitution,
            hitpoints: this.hitpoints

        });
  }
  static generateAbilityScore() {
    console.log("🎲 رمي أحجار النرد...");
    const rolls = [];
        for (let i = 0; i < 4; i++) {
            const roll = Math.floor(Math.random() * 6) + 1;
            rolls.push(roll);
        }
        console.log(rolls)
       rolls.sort((a,b)=>b-a);
       const result = rolls[0] + rolls[1] + rolls[2];
       return result;
  } ;
}