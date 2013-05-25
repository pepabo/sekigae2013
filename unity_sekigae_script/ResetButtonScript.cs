using UnityEngine;
using System.Collections;

public class ResetButtonScript : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    void ResetScript()
    {
        Application.LoadLevel(0);
    }
}
