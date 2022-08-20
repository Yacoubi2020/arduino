#define PWMout  2   // Signal PWM de référence 

bool State=false; 

void setup()
{
  // Initialisation de la sortie PWM (signal carré, rapport cyclique 50%)  
  analogWrite(PWMout, 128);
  
  // Câblage du pin et configuration en entrée: INT0 => PD0 (pin 38 de la carte)
  DDRD =0x00; // Port D en entrée 

  // Activation de l'interruption globale (registre SREG)  
  SREG|=0x80; 
      //SREG|=0x80  // Activation 
      //SREG&=0x7f  // Désactivation  
      //Ou bien 
      //sei(): Set interrupt - Activation 
      //cli(): clear interrup - Désactivation (masquer)   

  // Validation de l'interruption INT0 (Registre EIMSK)
  EIMSK|=0x01; // INT0 
      //EIMSK|=0x02; // INT1
      //EIMSK|=0x04; // INT0
      //... 
  // Choix du mode de détection: Front montant dans INT0 
  EICRA|=0x03; 
      //EICRA|=0x00;  //niveau bas '0' dans INTn
      //EICRA|=0x01;  //front montant ou descendant dans INTn
      //EICRA|=0x02;  //Front descendant dans INTn 
      //EICRA|=0x03;  //Front montant dans INTn 

  // Initialisation du port A en sortie 
     DDRB =0xff; 
     PORTB=0x00;
}

void loop()
{
  // Au chaumage  
}

// Routine d'interruptions : Pour chaque front montant on inverse l'état 
// du port A (8 sorties synchrones) 

ISR(INT0_vect){
  State=not(State);
  PORTB=State*0xff; //State&0xff;
}
