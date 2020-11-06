# PLL_Demdulator
In the first place, the story is "What is a demodulator?", But the process of converting "low-frequency piro-piro sound" to "0101 digital signal" is demodulation, and noise when transmitting wirelessly. Various manufacturers and amateurs are competing for performance in terms of how to eliminate the effects of interference and fading and extract a beautiful binary signal.


# circuit
The circuit is introduced by saying that Harry Lythall (SM0VPO).
This circuit may be connected directly across your rig speaker terminal and used to drive a teleprinter coil directly. A normal teleprinter coil requires 80/80 volts to energise the coil, but this is connected in series with a 2.7K resistor to give a sort of constant current. The teleprinter coil never has more than 20 volts accross it, so we can use semiconductors to limit the current with a supply voltage of less than 30 volts. With no signal, adjust the 4K7 potentiometer for a frequency of 1360 Hz at pins 4/5 of the NE565. Set the 1M0 pot so that the teleprinter just stops 'racing' or 'marking' (continuously going Chunk-Chunk-Chunk-Chu...). The teleprinter switch S1 reverses the sensitivity of the decoder. Some operators used to send the tones backwards (or perhaps I always sent my tones backwards!!).

The output of the two OpAmps may be used to feed a computer, each OpAmp gives the received RTTY signal in the opposite phase. The output of an OpAmp is 8v reversals that can be used to feed an RS232 input. It may be simply modified to provide a TTL output if desired (clip to +ve only with diode and attenuate to 5v).

The encoder may be a simple two transistor multivibrator. If polystyrene capacitors are used then the frequency stability will be more than adequate, even without a regulated supply.
[circuit](https://github.com/Sayapatri/baudot_decoder/blob/main/diagram/MO_DEMO-l.jpg)
