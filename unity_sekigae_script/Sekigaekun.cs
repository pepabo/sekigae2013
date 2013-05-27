    using UnityEngine;
    using System.Collections;

    public class Sekigaekun : MonoBehaviour {
    const int LEFT = -700;
    const int RIGHT = 700;

    private float speed;
    private int direction;

    private bool isSearchStart;
    private int arrivedPoint;

    private Animator animator;

    void Awake()
    {
        speed = Random.Range(4, 10);
    }
    // Use this for initialization
    void Start () {
        animator = GetComponent<Animator>();

        direction = Random.Range(0, 2) == 0 ? 1 : -1;
        animator.SetInteger("dir", direction);
    }
	
    // Update is called once per frame
    void Update () {
        if (isSearchStart) { Search(); }
        transform.localPosition += Vector3.right * speed * direction;
        OutLineCheck();
    }

    private void OutLineCheck()
    {
        float x = transform.localPosition.x;
        if (x < LEFT | x > RIGHT) 
        {
            direction *= -1;
            animator.SetInteger("dir", direction);
        }
    }

    public void SetArivved(int arrived)
    {
        arrivedPoint = arrived;
        isSearchStart = true;
    }

    private void Search()
    {
        float x = transform.localPosition.x;
        if (Mathf.Abs(x - arrivedPoint) < 10) 
        {
            animator.SetBool("isArrived", true);
            Destroy(this);
        }
    }
}
