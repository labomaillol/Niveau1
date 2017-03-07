using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class lancer : MonoBehaviour {
	//Variable qui définit la vitesse de la balle
	public float speed=5f;
	//Variable qui definit si l'utilisateur a appuyé sur Fire1
	public int run = 0;
	//Variable qui regroupe les caractéristiques d'interaction de la sphere.
	public Rigidbody sp;
	//On définit tous les cubes

	// Use this for initialization
	void Start () {
		sp = GetComponent<Rigidbody>();
		transform.position = new Vector3 (0f, 1.8f, -4.66f);
		}
		
	void Update () {

		//Permet de déplacer la balle parallelement à la camera 
		float h = Input.GetAxis("Horizontal");
		transform.position += new Vector3 (h*0.1f , 0f , 0f);

		//Pour l'exporter sur Android
		transform.position += new Vector3 (Input.acceleration.x*0.1f , 0f , 0f);

		//Verifie si on clique Fire1 (Ctrl de gauche ou bouton souris)
		if (Input.GetButtonDown ("Fire1")) {
			run = 1;
		}
		//Si fire1 a été appuyé on lance la balle.
		if (run == 1) {
			transform.position += new Vector3 (0f , 0f , speed*0.1f);
		}
		//Si la balle tombe on réinitialise le tout
		if (transform.position.y < 0) {
			run = 0;
			transform.position= new Vector3 (0f, 1.8f, -4.66f);
			sp.velocity = Vector3.zero;
			sp.angularVelocity = Vector3.zero;
		}
			
	}
}
