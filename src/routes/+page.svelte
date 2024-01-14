<script>
	import DataTable from './DataTable.svelte';
	import { getApp } from "firebase/app";
	import { getDatabase, ref, onValue, get, child } from "firebase/database";
	const app = getApp();
	const database = getDatabase(app);
	const TemperatureSensorsLive = ref(database, 'TemperatureSensorsLive');
	const TemperatureSensorsHistory = ref(database, 'TemperatureSensorsHistory');
	const MoistureSensorsLive = ref(database, 'MoistureSensorsLive');
	const MoistureSensorsHistory = ref(database, 'MoistureSensorsHistory');
	/** @type {number[] | null} */
	let tempLive;
	/** @type {number[][] | null} */
	let tempHistory;
	/** @type {number[] | null} */
	let moistureLive;
	/** @type {number[][] | null} */
	let moistureHistory;
	const tempLiveProm = get(TemperatureSensorsLive).then((snapshot) => {
		tempLive = snapshot.val();
	});
	const tempHistoryProm = get(TemperatureSensorsHistory).then((snapshot) => {
		tempHistory = snapshot.val();
	});;
	const moistureLiveProm = get(MoistureSensorsLive).then((snapshot) => {
		moistureLive = snapshot.val();
	});;
	const moistureHistoryProm = get(MoistureSensorsHistory).then((snapshot) => {
		moistureHistory = snapshot.val();
	});;
	onValue(TemperatureSensorsLive, (snapshot) => {
		tempLive = snapshot.val();
	});
	onValue(TemperatureSensorsHistory, (snapshot) => {
		tempHistory = snapshot.val();
	});
	onValue(MoistureSensorsLive, (snapshot) => {
		moistureLive = snapshot.val();
	});
	onValue(MoistureSensorsHistory, (snapshot) => {
		moistureHistory = snapshot.val();
	});
</script>

<svelte:head>
	<title>Web Page Layout</title>
</svelte:head>
<DataTable />
