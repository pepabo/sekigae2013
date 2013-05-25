using UnityEngine;
using System.Collections;

public class StopButton : MonoBehaviour {

    private ArrayList arrivedPosition = new ArrayList();
    public Sekigaekun[] sekigaes;
    private UILabel label;

    void Awake() {
        arrivedPosition.AddRange(new int[] { -700, -235, 230, 700 });
    }
	// Use this for initialization
	void Start () {
        label = GetComponentInChildren<UILabel>();
	}
	
	// Update is called once per frame
	void Update () {

        bool isAlldead = true;
        foreach (var n in sekigaes) 
        {
            if (n != null) { isAlldead = false; break; }
        }
        if (isAlldead) { label.text = "done"; }
	}

    void StopFreeWalking()
    {
        var sekigaeArray = SekigaeLogic.Sekigsae(arrivedPosition);

        for (int i = 0; i < sekigaes.Length; i++)
        {
            sekigaes[i].SetArivved((int)sekigaeArray[i]);
        }

        label.text = "Sekigae Now..";
    }
}
