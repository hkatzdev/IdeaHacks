import { getApps, getApp, initializeApp } from 'firebase/app';
import { getDatabase } from 'firebase/database';
import { GoogleAuthProvider, signInWithRedirect, getRedirectResult, getAuth } from 'firebase/auth';
//import { PUBLIC_FIREBASE_CONFIG } from "$env/static/public";

export const getFirebaseApp = () => {
	const PUBLIC_FIREBASE_CONFIG =
		'{"apiKey":"AIzaSyC1xjg63DvNlzAzQ7GjnxBeMZPfY2EHmmw","authDomain":"arduinodatatable.firebaseapp.com","databaseURL":"https://arduinodatatable-default-rtdb.firebaseio.com","projectId":"arduinodatatable","storageBucket":"arduinodatatable.appspot.com","messagingSenderId":"407146302691","appId":"1:407146302691:web:f8f4c130869a40a98349d6"}';
	const app = getApps().length ? getApp() : initializeApp(JSON.parse(PUBLIC_FIREBASE_CONFIG));

	return app;
};

/**
 * @typedef {import ("firebase/app").FirebaseApp} FirebaseApp
 * @param {FirebaseApp} app
 */
export const getFirebaseInfo = (app) => {
	const auth = getAuth(app);
	const database = getDatabase(app);
	return { auth, database };
};

/**
 * @typedef {import ("firebase/auth").Auth} Auth
 * @param {Auth} auth
 */
export const signIntoFirebase = (auth) => {
	if (!auth.currentUser) {
		const provider = new GoogleAuthProvider();
		signInWithRedirect(auth, provider);
	}
};
