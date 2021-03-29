using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class boxScript : MonoBehaviour
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
        if (Input.GetKeyDown(KeyCode.W))
        {
            //Debug.Log("Pressing W");
            //transform.Translate(Vector3.forward * Time.deltaTime*10);
            rigidbody.AddForce(Vector3.forward * 100);
        }

        if (Input.GetKeyDown(KeyCode.A))
        {
            //Debug.Log("Pressing A");
            //transform.Translate(Vector3.left * Time.deltaTime * 10);
            rigidbody.AddForce(Vector3.left * 100);
        }

        if (Input.GetKeyDown(KeyCode.S))
        {
            //Debug.Log("Pressing S");
            //transform.Translate(Vector3.back * Time.deltaTime * 10);
            rigidbody.AddForce(Vector3.back * 100);
        }

        if (Input.GetKeyDown(KeyCode.D))
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
