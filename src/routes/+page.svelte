<script>
	import { getDatabase, onValue, ref } from 'firebase/database';
	import DataTable from './DataTable.svelte';
	import Messages from './Messages.svelte';
	import { onMount } from "svelte";
	import { getFirebassApp } from "$lib/firebase";
	/** @type {import('./$types').PageData} */
	export let data;
	onMount(() => {
		const app = getFirebassApp();
		const database = getDatabase(app);
		const sensors = ref(database, 'sensors');
		onValue(sensors, (snapshot) => {
			data.temp[0] = snapshot.val().temperature1;
			data.moisture[0] = snapshot.val().moisture1;
			data.temp[1] = snapshot.val().temperature2;
			data.moisture[1] = snapshot.val().moisture2;
			data.temp[2] = snapshot.val().temperature3;
			data.moisture[2] = snapshot.val().moisture3;
		});
	});
</script>

<svelte:head>
	<title>Web Page Layout</title>
</svelte:head>
<DataTable liveTemps={data.temp} liveMoistures={data.moisture} />
<Messages liveTemps={data.temp} liveMoistures={data.moisture} />
