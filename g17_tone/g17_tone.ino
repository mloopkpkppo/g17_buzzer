

#include "pitches.h"


int melody[] = {
  // 第1段：嗡嗡嗡，嗡嗡嗡，大家一起勤作工
  // Sol Mi Mi, Fa Re Re, Do Re Mi Fa Sol Sol Sol
  NOTE_G4, NOTE_E4, NOTE_E4,
  NOTE_F4, NOTE_D4, NOTE_D4,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  
  // 第2段：來匆匆，去匆匆，做工興味濃
  // Sol Mi Mi, Fa Re Re, Do Mi Sol Sol Mi
  NOTE_G4, NOTE_E4, NOTE_E4,
  NOTE_F4, NOTE_D4, NOTE_D4,
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4,
  
  // 第3段：春暖花開不做工，將來哪裡好過冬
  // Re Re Re Re Re Mi Fa, Mi Mi Mi Mi Mi Fa Sol
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
  
  // 第4段：嗡嗡嗡，嗡嗡嗡，別學懶惰蟲
  // Sol Mi Mi, Fa Re Re, Do Mi Sol Sol Do
  NOTE_G4, NOTE_E4, NOTE_E4,
  NOTE_F4, NOTE_D4, NOTE_D4,
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_C4
};
int noteDurations[] = {
  // 第1段節拍
  4, 4, 2,
  4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,

  // 第2段節拍
  4, 4, 2,
  4, 4, 2,
  4, 4, 4, 4, 2,

  // 第3段節拍
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,

  // 第4段節拍
  4, 4, 2,
  4, 4, 2,
  4, 4, 4, 4, 2
};
void setup() {

}

void loop() {
  int numNotes = sizeof(melody) / sizeof(melody[0]);
   // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < numNotes; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    if (melody[thisNote] == NOTE_C4) {
      digitalWrite(2, HIGH); // 開燈
    }
    if (melody[thisNote] == NOTE_D4) {
      digitalWrite(3, HIGH); // 開燈
    }
    if (melody[thisNote] == NOTE_E4) {
      digitalWrite(4, HIGH); // 開燈
    }
    if (melody[thisNote] == NOTE_F4) {
      digitalWrite(5, HIGH); // 開燈
    }
    if (melody[thisNote] == NOTE_G4) {
      digitalWrite(6, HIGH); // 開燈
    }
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
  delay(200);
}
