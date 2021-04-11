using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class eliminationRect : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public mainScene mainSceneObject;

    void OnCollisionEnter(Collision other)
    {
        Debug.Log("Rect has been hit by " + other.gameObject.name + ". Destroying the object");

        //If you want to specific which type of object
        //You can specify by checking the colliding object's name
        if (other.gameObject.name == "Sphere(Clone)")
        {
            Destroy(other.collider.gameObject);
            mainSceneObject.destroyedCounter++;
        }
        
    }


}
