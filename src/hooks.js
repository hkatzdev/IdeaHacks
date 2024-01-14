import { redirect } from '@sveltejs/kit';
import { getApps, getApp, initializeApp } from "firebase/app";
import { getAuth } from "firebase/auth";

const firebaseConfig = {
  apiKey: "AIzaSyC1xjg63DvNlzAzQ7GjnxBeMZPfY2EHmmw",
  authDomain: "arduinodatatable.firebaseapp.com",
  databaseURL: "https://arduinodatatable-default-rtdb.firebaseio.com",
  projectId: "arduinodatatable",
  storageBucket: "arduinodatatable.appspot.com",
  messagingSenderId: "407146302691",
  appId: "1:407146302691:web:f8f4c130869a40a98349d6",
};


/** @type {import('@sveltejs/kit').Handle} */
export async function handle({ event, resolve }) {
  const path = event.url.pathname;
  if (path != "/about" && !path.startsWith("/static/")) {
    const app = getApps().length ? getApp() : initializeApp(firebaseConfig);
    const auth = getAuth(app);
    if (!auth.currentUser) {
      throw redirect(303, '/about');
    }
  }
  const response = await resolve(event);
	return response;
}
