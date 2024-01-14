import { getFirebaseApp, getFirebaseInfo } from '$lib/firebase.js';
import { redirect } from '@sveltejs/kit';


/** @type {import('@sveltejs/kit').Handle} */
export async function handle({ event, resolve }) {
	const path = event.url.pathname;
	if (!path.startsWith("/static/") && !path.startsWith("/login")) {
		const app = getFirebaseApp();
		const {auth} = getFirebaseInfo(app);
		if (!auth.currentUser) {
			redirect(303, "/login");
		}
	}
	const response = await resolve(event);
	return response;
}