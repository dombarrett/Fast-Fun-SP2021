using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//If using UI elements (Canvas, text, etc)
//You need to include the UI part of the engine

using UnityEngine.UI;

public class mainScene : MonoBehaviour
{

    public int destroyedCounter;

    //"Text" will not be an available data type until you add "using UnityEngine.UI;"
    public Text displayText;

    public GameObject myPrefab;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //Debug.Log(destroyedCounter + " gameobjects have been destroyed");

        displayText.text = destroyedCounter + " shapes destroyed";

        //You can use modulo as a counter when used in conjunction with frameCount
        //Debug.Log(Time.frameCount%120);

        if (Time.frameCount % 200 == 0)
        {
            Debug.Log("Ding!");
            Instantiate(myPrefab, new Vector3(0, 5, 0), Quaternion.identity);
        }
    }
}
