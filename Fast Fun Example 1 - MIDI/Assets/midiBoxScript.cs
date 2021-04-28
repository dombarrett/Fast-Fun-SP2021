using System.Collections;
using System.Collections.Generic;
using UnityEngine;


//MIDI version of the original boxScript
//We need to import the MIDI Jack library we downloaded
//And add it to any script we want to use it with
using MidiJack;


public class midiBoxScript : MonoBehaviour
{
    Rigidbody rigidbody;


    // Start is called before the first frame update
    void Start()
    {
        rigidbody = this.GetComponent<Rigidbody>();
    }


    

    // Update is called once per frame
    void Update()
    {
        Debug.Log(MidiMaster.noteOnDelegate);

        //Originally, we checked for keypresses
        //if (Input.GetKeyDown(KeyCode.W))

        //Now we check for MIDI notes
        if(MidiMaster.GetKeyDown(61))
        {
            Debug.Log("MIDI Note 61");
            //transform.Translate(Vector3.forward * Time.deltaTime*10);
            rigidbody.AddForce(Vector3.forward * 100);
        }

        if (MidiMaster.GetKeyDown(62))
        {
            //Debug.Log("Pressing A");
            //transform.Translate(Vector3.left * Time.deltaTime * 10);
            rigidbody.AddForce(Vector3.left * 100);
        }

        if (MidiMaster.GetKeyDown(63))
        {
            //Debug.Log("Pressing S");
            //transform.Translate(Vector3.back * Time.deltaTime * 10);
            rigidbody.AddForce(Vector3.back * 100);
        }

        if (MidiMaster.GetKeyDown(64))
        {
            //Debug.Log("Pressing D");
            //transform.Translate(Vector3.right * Time.deltaTime * 10);
            rigidbody.AddForce(Vector3.right * 100);
        }


        //4-28-2021
        //MIDI CC Messages

        //The following code works with the "SmoothedAnalog_CC-MIDI.ino" Arduino sketch in the class Github

        //This Unity MIDI library describes CC messages as "knobs"- like the knobs on a synthesizer
        //They are not like piano keys, so they don't send on/off note messages
        //But send general information about a knob (or slider, or any potentiometer) being turned

        //To listen to MIDI CC1, CC2, etc you need to call MidiMaster.GetKnob(1), MidiMaster.GetKnob(2), and so on
        Debug.Log(MidiMaster.GetKnob(1) + "," + MidiMaster.GetKnob(2));


        //This MIDI library has decided to do some translation for us
        //Notice that the numbers we receive are floating point (fractions) between 0 and 1
        //To note here- the resolution of these numbers will still be from 0-127 (as are all standard MIDI messages)

        //The question is, now that we have analog values- how best to use them?
        //That is up to you
        //The different types of "digital" interactions vs "analog" interactions may be more or less appropriate for certain things


        //Take the MIDI value and adjust it as needed
        float ccToAngleRotation = MidiMaster.GetKnob(1)*3.0f;

        //What if we spun the box? On what axis?
        //Look at the rotation documentation here: https://docs.unity3d.com/ScriptReference/Transform.Rotate.html

        rigidbody.transform.Rotate(0.0f, ccToAngleRotation, 0.0f, Space.Self);

        //Note: Space.Self indicates the point you are rotating around
        //Is the center of rotation the object, or a point in the game world?
        //In our case, we want it to be the box, or the object "Self" this script is attached to


    }

    

    void OnCollisionEnter(Collision other)
    {
        Debug.Log("Cube has been hit by " + other.gameObject.name);
    }
}
