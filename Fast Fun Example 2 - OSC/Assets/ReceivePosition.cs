using UnityEngine;
using System.Collections;

public class ReceivePosition : MonoBehaviour {


    //public game object with OSC script attached to it
    //that game object will be placed in the necessary spot in the inspector
    //which will then give this script access to the OSC library
   	public OSC osc;


	// Use this for initialization
	void Start () {
        /*
            This is modified from the example project for the OSC library
            We will play with these in class

            We are setting what OSC message to listen to ("/CubeX", "/publish/func", etc)
            Then we are assigning a function for each one of those messages
            The contents of the OSC message will be passed into those functions
            At which point we can do what we want with them
        */

        //osc.SetAddressHandler("/CubeXYZ", OnReceiveXYZ);
        //osc.SetAddressHandler("/CubeX", OnReceiveX);
        //osc.SetAddressHandler("/CubeY", OnReceiveY);
        osc.SetAddressHandler("/CubeZ", OnReceiveZ);

        //osc.SetAddressHandler("/UpdateXYZ", OnReceiveXYZ);
        osc.SetAddressHandler("/UpdateX", OnReceiveX);
        //osc.SetAddressHandler("/UpdateY", OnReceiveY);
        //osc.SetAddressHandler("/UpdateZ", OnReceiveZ);

        //osc.SetAddressHandler("/OnMouseDownX", OnReceiveX);
        osc.SetAddressHandler("/OnMouseDownY", OnReceiveY);
        //osc.SetAddressHandler("/OnMouseDownZ", OnReceiveZ);



        //Making your own, from the Arduino example
        //Remember- what ports are you sending and receiving on?
        //Arduino example may be different (54445)
        //
        osc.SetAddressHandler("/publish/func", fromArduino);

    }
	
	// Update is called once per frame
	void Update () {
	
	}


    //Here are four functions that are trigger when specific OSC messages are received:

    void fromArduino(OscMessage message)
    {
        //We can define our own functions that are called when OSC messages are received
        
        //We can show the entire OSC message we receive
        Debug.Log("Receiving from Arduino:");
        Debug.Log(message);


        //Or when multiple values are being sent,
        //You can access them invididually

        //int button1State = message.GetInt(0);
        //int button2State = message.GetInt(1);
        //int button3State = message.GetInt(2);
        //int button4State = message.GetInt(3);
        //int button5State = message.GetInt(4);

        //Debug.Log("button1State "+ button1State);
        //Debug.Log("button2State "+ button2State);
        //Debug.Log("button3State "+ button3State);
        //Debug.Log("button4State "+ button4State);
        //Debug.Log("button5State "+ button5State);
    }


    void OnReceiveXYZ(OscMessage message){
		float x = message.GetInt(0);
         float y = message.GetInt(1);
		float z = message.GetInt(2);

		transform.position = new Vector3(x,y,z);
	}

    void OnReceiveX(OscMessage message) {
        float x = message.GetFloat(0);

        Vector3 position = transform.position;

        position.x = x;

        transform.position = position;
    }

    void OnReceiveY(OscMessage message) {
        float y = message.GetFloat(0);

        Vector3 position = transform.position;

        position.y = y;

        transform.position = position;
    }

    void OnReceiveZ(OscMessage message) {
        float z = message.GetFloat(0);

        Vector3 position = transform.position;

        position.z = z;

        transform.position = position;
    }


}
