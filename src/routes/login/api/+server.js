import { getFirebaseApp, getFirebaseInfo } from '$lib/firebase.js';
import {redirect} from "@sveltejs/kit";
import { GoogleAuthProvider, signInWithCredential } from "firebase/auth";
/**
 * @param {{ credential: string; }} response
 */

/** @type {import('./$types').RequestHandler} */
export async function POST({request}) {

	// @ts-ignore
	const app = getFirebaseApp();
	const { auth } = getFirebaseInfo(app);
	// @ts-ignore
	const credential = GoogleAuthProvider.credential((await request.formData()).get("credential"));
	// Sign in with credential from the Google user.
	await signInWithCredential(auth, credential);

	redirect(303, "/");
}
