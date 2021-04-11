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
    }

    

    void OnCollisionEnter(Collision other)
    {
        Debug.Log("Cube has been hit by " + other.gameObject.name);
    }
}
