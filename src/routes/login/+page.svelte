<script context="module">
  import { getFirebaseApp, getFirebaseInfo } from '$lib/firebase.js';
  import { GoogleAuthProvider, signInWithCredential } from "firebase/auth";
  /**
   * @param {{ credential: string; }} response
   */
  const app = getFirebaseApp();
  const {auth} = getFirebaseInfo(app);
  /**
	 * @param {{ credential: string; }} response
	 */
  export function handleCredentialResponse(response) {
    const idToken = response.credential;
    const credential = GoogleAuthProvider.credential(idToken);
    signInWithCredential(auth, credential);
  }
</script>

<svelte:head>
   <script src="https://accounts.google.com/gsi/client" async></script>
</svelte:head>
<style>
</style>
<div id="g_id_onload"
     data-client_id="407146302691-3h6dv8f44d38sr40pn3i3ql3s2164b16.apps.googleusercontent.com"
     data-context="use"
     data-ux_mode="redirect"
     data-login_uri="http://localhost:5173/login/api"
     data-auto_prompt="false">
</div>

<div class="g_id_signin"
     data-type="standard"
     data-shape="pill"
     data-theme="outline"
     data-text="continue_with"
     data-size="large"
     data-logo_alignment="left">
</div>
